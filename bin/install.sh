#!/bin/bash

set -euo pipefail

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
REPO_ROOT=$( cd -- "$SCRIPT_DIR/.." && pwd )
TARGET_DIR="$HOME/lautanette"
TEMP_DIR=$(mktemp -d "$HOME/.lautanette-install.XXXXXX")
USE_REMOTE=0

if [[ ! -d "$REPO_ROOT/.git" || "${LAUTANETTE_INSTALL_REMOTE:-0}" == "1" ]]; then
	USE_REMOTE=1
fi

cleanup() {
	rm -rf "$TEMP_DIR"
}
trap cleanup EXIT


copy_tree() {
	local source=$1
	local destination=$2
	if command -v rsync &> /dev/null; then
		rsync -a "$source/" "$destination/"
	else
		cp -a "$source/." "$destination/"
	fi
}

if [[ $USE_REMOTE -eq 1 ]]; then
	echo "Installing Lautanette from the official repository"
	git clone --recursive https://github.com/ljfp/lautanette.git "$TEMP_DIR/repo"
else
	echo "Installing Lautanette from local checkout: $REPO_ROOT"
	if ! command -v rsync &> /dev/null; then
		echo "rsync is required to install from a local checkout. Falling back to remote clone."
		git clone --recursive https://github.com/ljfp/lautanette.git "$TEMP_DIR/repo"
		USE_REMOTE=1
	else
		rsync -a --delete --exclude='.git/modules/' --exclude='.venv/' --exclude='.mypy_cache/' \
			--exclude='__pycache__/' "$REPO_ROOT/" "$TEMP_DIR/repo/"
	fi
fi

if [[ $USE_REMOTE -eq 0 ]]; then
	# ensure submodules (if any) are initialised in the staging directory
	if [[ -f "$TEMP_DIR/repo/.gitmodules" ]]; then
		( cd "$TEMP_DIR/repo" && git submodule update --init --recursive >/dev/null 2>&1 || true )
	fi
fi

if [[ -d "$TARGET_DIR" ]]; then
	echo "Removing previous installation in $TARGET_DIR"
	rm -rf "$TARGET_DIR"
fi

mkdir -p "$TARGET_DIR"
copy_tree "$TEMP_DIR/repo" "$TARGET_DIR"

SKIP_SYSTEM_DEPS=${LAUTANETTE_SKIP_SYSTEM_DEPS:-0}

if [[ "$(uname)" != "Darwin" && "$SKIP_SYSTEM_DEPS" != "1" ]]; then
	echo "Admin permissions needed to install system dependencies (gcc, python, valgrind, ...)"
	case $(lsb_release -is) in
		"Ubuntu")
			sudo apt update
			sudo apt upgrade
			sudo apt install gcc clang libpq-dev libbsd-dev libncurses-dev valgrind -y
			sudo apt install python-dev python3-pip python3-dev python3-venv python3-wheel -y
			if command -v pip3 &> /dev/null; then
				pip3 install --user --upgrade wheel
			fi
			;;
		"Arch")
			sudo pacman -Syu
			sudo pacman -S gcc clang postgresql libbsd ncurses valgrind python-pip --noconfirm
			if command -v pip3 &> /dev/null; then
				pip3 install --user --upgrade wheel
			fi
			;;
	esac
elif [[ "$SKIP_SYSTEM_DEPS" == "1" ]]; then
	echo "Skipping system dependency installation (LAUTANETTE_SKIP_SYSTEM_DEPS=1)."
fi

cd "$TARGET_DIR"

echo "Creating virtual environment..."
python3 -m venv venv

echo "Installing Python dependencies..."
"$TARGET_DIR/venv/bin/pip" install --upgrade pip
"$TARGET_DIR/venv/bin/pip" install -r requirements.txt

RC_FILE="$HOME/.zshrc"
if [[ "$(uname)" != "Darwin" ]]; then
	RC_FILE="$HOME/.bashrc"
	if [[ -f "$HOME/.zshrc" ]]; then
		RC_FILE="$HOME/.zshrc"
	fi
fi

echo "try to add alias in file: $RC_FILE"

if ! grep "lautanette=" "$RC_FILE" &> /dev/null; then
	echo "lautanette alias not present"
	printf "\nalias lautanette=%s/lautanette/tester.sh\n" "$HOME" >> "$RC_FILE"
fi

if ! grep "paco=" "$RC_FILE" &> /dev/null; then
	echo "Short alias not present. Adding it"
	printf "\nalias paco=%s/lautanette/tester.sh\n" "$HOME" >> "$RC_FILE"
fi

"$TARGET_DIR/tester.sh" --help

printf "\033[33m... and don't forget, \033[1;37mpaco\033[0;33m is not a replacement for your own tests! \033[0m\n"

exec "$SHELL"