FROM        debian:jessie
RUN         apt-get update && apt-get -qq install build-essential tree lintian
RUN         mkdir /lab
VOLUME      ["/lab"]
ADD         distribution/debian/package     bomberman
ADD         maps                            bomberman/DEBIAN/usr/bin/maps
COPY        Makefile                        bomberman/DEBIAN/usr/bin/
ADD         src                             bomberman/DEBIAN/usr/bin/src
WORKDIR     /bomberman/DEBIAN/usr/bin/
RUN         mkdir bin/&& make && make clean && rm -rf src/ && mv bin/* . && rm -rf bin
WORKDIR     /
RUN         tree bomberman
RUN         mv  /bomberman/DEBIAN/usr/bin/Makefile .
RUN         dpkg-deb --build bomberman
RUN         lintian bomberman.deb && dpkg -i bomberman.deb
ENTRYPOINT  ["mv", "bomberman.deb", "lab"]
