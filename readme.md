## Peach Boy

A 2D side-scrolling platformer written in c++ using the cocos2d-x framework. Based on the japanese fairy tale of the same name.

### Supported Platforms

- Linux (Source only)
- Windows (Binary / Source)
- Mac/Android may be supported in the future

### Installing on Linux

Using Ubuntu 14.10:

```sh
sudo apt-get install build-essential \
    git cmake xorg-dev libglu1-mesa-dev \
    libcurl3-openssl-dev && \
    git clone http://github.com/xxami/neko-platformer.git && \
    cd neko-platformer && git submodule init && git submodule update && \
    git clone http://github.com/nigels-com/glew.git && \
    cd glew && make extensions && make && \
    sudo make install && cd .. && cmake . && make
```

The resulting binary will be in **bin/**

Using other distros: Those packages should not be too difficult to hunt down using Google.  I hope I can make this easier soon, sorry!

### Installing on Windows

Either get the binary from the github downloads page, or:

```sh
git clone http://github.com/xxami/neko-platformer.git && \
    cd neko-platformer && git submodule init && git submodule update
```

The source can be built using Visual Studio 2013 with the projects provided in **proj.win32/**

### License

The Peach Boy source code in **game/** is released under the public domain, but it is powered by cocos2d-x which uses many libraries with differing licenses. Please see **cocos2d/licenses/**


