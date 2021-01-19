# R-type

## Install

### With Nix
If you don't have nix yet run `curl -L https://nixos.org/nix/install | sh` and read output messages
```shell script
nix-shell shell.nix  # This will install all dependencies in a separate environment
make
```

## USAGE

### Server
```
cd server
./r-type-server
```

### Client
```
cd client
./client [server_ip] <server_port>
```
