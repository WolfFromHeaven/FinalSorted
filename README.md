# FinalSorted
Latest Working code

* Following set of commands need to be used in StarCluster
```
starcluster start NameOfCluster
starcluster sshmaster NameOfCluster
```
* You become the root user. Use these 2 commands in case all the processes are detected as root process (Check with hello_world.cc program and see if each process shows a different rank)
```
root@master: apt-get remove mpich2
root@master: apt-get autoremove
```
* Setting bandwidth limits on incoming and outgoing traffic on each node of the cluster (nodes can be individually accessed
as follows: starcluster sshnode nodeId)
```
tc qdisc add dev eth0 handle 1: root htb default 11
tc class add dev eth0 parent 1: classid 1:1 htb rate 1000Mbps
tc class add dev eth0 parent 1:1 classid 1:11 htb rate 1000Mbit
```
* The bandwidths that have been set can be checked using iperf
```
apt-get install iperf
iperf -s (on the server side)
iperf -c serverIpAddress (on the client side)
```
* Input file for the code can be generated by compiling and running the `DataCreator.c`. e.g.: For 1GB data, number of rows is 10^7. 
* At root node, clone this file from git. Use MakeFile to compile it.
```
sgeadmin@master:~PartialSort$ make
sgeadmin@master:~PartialSort$ ./Splitter 
sgeadmin@master:~PartialSort$ mpirun -n 4 -hostfile ./hosts ./CodedPartialSort
```
