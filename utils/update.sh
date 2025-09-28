#!/bin/bash

# FIXME: Remove after some time (because of the updater)

cd "$HOME" || exit

mkdir temp_____

if [ "$(uname)" != "Darwin" ]; then
	echo "Admin permissions need to install newer packages"
	sudo apt install libbsd-dev libncurses-dev
fi

cd temp_____ || exit
rm -rf lautanette

# download github
echo "Downloading lautanette repo..."
git clone --quiet --recursive https://github.com/ljfp/lautanette.git 2> /dev/null

cp -r lautanette .. 2> /dev/null

cd "$HOME" || exit
rm -rf temp_____

cd "$HOME"/lautanette || exit

# activate venv
. venv/bin/activate

echo "Updating python dependencies..."
# install requirements
if ! pip3 install --disable-pip-version-check -q -r requirements.txt ; then
	echo "Problem launching the installer. Contact me (fsoares- on slack)"
	exit 1
fi

echo -e "\033[1;37mLautanette is updated. You can use it again!\033[0m"
