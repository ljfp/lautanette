#!/bin/bash

if [ "$(uname)" != "Darwin" ]; then
	echo "Admin permissions need to install newer packages"
	sudo apt install libbsd-dev libncurses-dev
fi

cd "$HOME"/lautanette || exit

git fetch origin
git reset --hard origin/$(git symbolic-ref --short HEAD)

# activate venv
. venv/bin/activate

echo "Updating python dependencies..."
# install requirements
if ! pip3 install --disable-pip-version-check -q -r requirements.txt ; then
	echo "Problem updating lautanette. Contact the maintainer."
	exit 1
fi

echo -e "\033[1;37mLautanette is updated. You can use it again!\033[0m"

printf "\033[33m... but don't forget, \033[1;37mpaco\033[0;33m is not a replacement for your own tests! \033[0m\n"
