FROM epitechcontent/epitest-docker

WORKDIR /src/app/rtype

COPY . .

RUN conan remote add conan_center https://api.bintray.com/conan/conan/conan-center
RUN conan remote add epitech https://api.bintray.com/conan/epitech/public-conan
RUN conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan

RUN rm -rf `cat .gitignore`
RUN ./build.py
