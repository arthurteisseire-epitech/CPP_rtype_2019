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
This is an educational project so there remains some bugs that we didn't fixed but what was important for us is:
- Monsters are loaded dynamically.
- You can play in the same local network: Client / Server with home-made protocol following RFC 2119
- We achieve to create an ECS (Entity Component System) framework functionnal using template meta-programming. Networking, and dynamic monster loading are working in different threads thanks to a home-made thread-pool. Those are part of our ECS.
