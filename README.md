# bitmonkey-debug

Bitmonkey Core integration/staging tree


What is Bitmonkey? Bitmonkey is a clone of BitCoin ... Starting from Genesis Time = 0 ... and 

pszTimestamp = "The Times 03/Jan/2009 Chancellor on brink of monkey bailout for banks"

Not entering in any technical discussion if you wish to try an install Bitmonkey I would like to suggest to use Oracle VM VirtualBox
you can donload it at ... https://www.virtualbox.org/wiki/Downloads after installing the last available version remember to install too "Oracle VM VirtualBox Extension Pack" https://download.virtualbox.org/virtualbox/6.0.10/Oracle_VM_VirtualBox_Extension_Pack-6.0.10.vbox-extpack .

Once VB is installed download the ubuntu-16.04.6-desktop-amd64.iso http://it.releases.ubuntu.com/16.04/ubuntu-16.04.6-desktop-amd64.iso 
and install it in VB.

Now I Will list the requirement you need to install to download and install Bitmonkey on Ubuntu 16.04.6 starting from scratch up to the end.

Before you start please be sure your Virtual Machine is update Open the terminal and run this comand ...

-------- sudo apt update && sudo apt dist-upgrade && sudo apt autoremove --------

-------- List of depency you should have installed on your Virtual Machine to finally install Bitmonkey : the following ...

$ sudo apt-get install git

$ git clone https://github.com/pbitmonkey/bitmonkey-debug.git

$ sudo apt-get install autoconf libtool pkg-config

$ sudo apt-get install gawk

$ sudo apt-get install g++ make

$ sudo apt install libboost-all-dev

$ sudo apt-get install bsdmainutils

$ sudo apt-get install openssl libssl-dev

$ sudo apt-get install build-essential autotools-dev

$ note : Ubuntu 12.04 and later have packages for libdb5.1-dev and libdb5.1++-dev

$ but using these will break binary wallet compatibility, and is not recommended, so do it ...

$ sudo add-apt-repository ppa:bitcoin/bitcoin

$ sudo apt-get update

$ sudo apt-get install libdb4.8-dev libdb4.8++-dev

$ sudo apt-get install libminiupnpc-dev

$ sudo apt-get install libqt4-dev libprotobuf-dev protobuf-compiler

$ sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools

$ sudo apt-get install libqrencode-dev

$ sudo apt-get install autotools-dev automake python3

$ sudo apt-get install libevent-dev libboost-system-dev libboost-filesystem-dev libboost-chrono-dev libboost-test-dev libboost-thread-dev

$ sudo apt-get install libzmq3-dev

$ sudo apt-get install libqrencode-dev

$ sudo apt-get install doxygen

cd bitmonkey-debug

serch for ... 

$ ../bitmonkey-debug/autogen.sh change permission to "autogen.sh" allow program esecution.

$ ../share/genbuild.sh change permission to "genbuild.sh" allow program esecution.

--- Close all the windows and terminals open.

$ Point bitmonkey-debug and open in terminal ... then type ...

$ ./autogen.sh ... wait it finish ... then type ..

$ ./configure --with-incompatible-bdb ... wait it finish ... then type ...

$ make ... let it run it will take some time ...

$ when it finish optional ... type 

$ make install.


Bitmonkey is an experimental digital currency that enables instant payments to anyone, anywhere in the world. Bitmonkey uses peer-to-peer technology to operate with no central authority: managing transactions and issuing money are carried out collectively by the network. Bitmonkey Core is the name of open source software which enables the use of this currency.

License
Bitmonkey Core is released under the terms of the MIT license. See COPYING for more information or see https://opensource.org/licenses/MIT.

The contribution workflow is described in CONTRIBUTING.md and useful hints for developers can be found in doc/developer-notes.md.

Testing
Testing and code review is the bottleneck for development; we get more pull requests than we can review and test on short notice. Please be patient and help out by testing other people's pull requests, and remember this is a security-critical project where any mistake might cost people lots of money.

Automated Testing
Developers are strongly encouraged to write unit tests for new code, and to submit new unit tests for old code. Unit tests can be compiled and run (assuming they weren't disabled in configure) with: make check. Further details on running and extending unit tests can be found in /src/test/README.md.

There are also regression and integration tests, written in Python, that are run automatically on the build server. These tests can be run (if the test dependencies are installed) with: test/functional/test_runner.py

The Travis CI system makes sure that every pull request is built for Windows, Linux, and macOS, and that unit/sanity tests are run automatically.

Manual Quality Assurance (QA) Testing
Changes should be tested by somebody other than the developer who wrote the code. This is especially important for large or high-risk changes. It is useful to add a test plan to the pull request description if testing the changes is not straightforward.

Translations
Changes to translations as well as new translations can be submitted to Bitmonkey Core's Transifex page.

Translations are periodically pulled from Transifex and merged into the git repository. See the translation process for details on how this works.

Important: We do not accept translation changes as GitHub pull requests because the next pull from Transifex would automatically overwrite them again.

Translators should also subscribe to the mailing list.
