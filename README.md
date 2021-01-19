# R-type

## Install

### With Nix
If you don't have nix yet run `curl -L https://nixos.org/nix/install | sh` and read output messages
```shell script
nix-shell shell.nix  # This will install all dependencies in a separate environment
cmake . && cmake --build .
```

## USAGE

### Server
```
cd server
./r-type_server
```

### Client
```
cd client
./r-type_client [server_ip] <server_port>
```

## Notes
This is an educational project. There remains some bugs but what was important for us is that monsters are loaded dynamically and Entity Component System framework we created using template meta-programming in the server.
