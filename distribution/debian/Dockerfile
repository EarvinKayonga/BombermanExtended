FROM        debian:jessie
RUN         apt-get update && apt-get -qq install build-essential tree
RUN         mkdir /lab
VOLUME      ["/lab"]
ADD         distribution/debian/package     bomberman
ADD         maps                            bomberman/DEBIAN/usr/bin/maps
COPY        Makefile                        bomberman/DEBIAN/usr/bin/
ADD         src                             bomberman/DEBIAN/usr/bin/src
WORKDIR     /bomberman/DEBIAN/usr/bin/
RUN         mkdir bin/&& make && make clean && rm -rf src/
WORKDIR     /
RUN         tree bomberman
RUN         mv  /bomberman/DEBIAN/usr/bin/Makefile .
RUN         dpkg-deb --build bomberman
ENTRYPOINT  ["mv", "bomberman.deb", "lab"]
