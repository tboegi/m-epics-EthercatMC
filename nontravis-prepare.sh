#!/usr/bin/env bash

# bash script to be able to run travis locally
# Make it possible to test a travis run locally,
# before pushing the branch

SETUP_PATH=.ci-local:.ci
export SETUP_PATH

if [ "$BASH_VERSINFO" -lt 4 ]
then
	if test -x /opt/local/bin/port; then
		# Mac ports
		if ! [ -x /opt/local/bin/bash ]
		then
			sudo port install bash
		fi
		exec /opt/local/bin/bash $0 "$@"
		APTGET="$SUDO port install"
	fi
	# brew (Mac)
	if test -x /usr/local/bin/brew; then
		if ! [ -x /usr/local/bin/bash ]
		then
			sudo brew install bash
		fi
		exec /usr/local/bin/bash $0 "$@"
	fi
	echo >&2 "Can not find bash version "
	echo >&2 "Unable to install bash version via port (mac ports)"
	echo >&2 "Unable to install bash version via brew"
	exit 1
fi

bash  -e -x .ci/travis/prepare.sh -v -v
