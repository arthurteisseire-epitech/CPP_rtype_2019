FROM epitechcontent/epitest-docker

WORKDIR /src/app/rtype

COPY client server build.py CMakeLists.txt conanfile.txt .gitignore .git ./

RUN conan remote add conan_center https://api.bintray.com/conan/conan/conan-center
RUN conan remote add epitech https://api.bintray.com/conan/epitech/public-conan
RUN conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan

RUN ./build.py
