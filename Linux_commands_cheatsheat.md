# General commands
Move files using rsync `rsync -avh /path/to/source/ /path/to/destination/

# Proxmox and homelab
## NFS
### Install (Debian)
`sudo apt-get install nfs-common`
`sudo nano /etc/fstab`
`<nfs-server-ip>:/path/to/nfs/share /mount/point nfs defaults  0  0`
`sudo systemctl daemon-reload`

## Proxmox Hosts
### Node Management
Deleting a node from the cluster `pvecm delnode <nodename>`

## Game Server Commands
### Minecraft
Command to make a backup of `home` directory to `backups` without including the `backups` folder

```
tar --exclude='./backups' -czvf home