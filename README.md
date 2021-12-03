# Bitcoin Toy Miner

This program is an analog to a Bitcoin miner. It receives a string of characters of any length as input and increases a nonce, which is concateneted with the string, at each round of double hash verifying if the digest is lower than a specific target. The target is stablished through the difficulty input wich ranges from 0 to 234. The difficulty is a 256 bit number where 0 difficulty corresponds to 2^256/2, meaning 50% chance of achieving the target for any iteration. The 234 difficulty corresponds to the maximum difficulty hard coded as 0x200000. As comparison Bitcoin lowest difficulty (highest target) would be equivalent to 31 in this miner. The nonce is a 4 byte number allowing 2^32 iterations but in this implemantation it is restricted to 3 bytes, althought the program allows a wider range of different values for the restriction up to 2^32.

## Features

The program has double hash SHA256 feature that is present in Bitcoin and also has a granular choosing for the difficulty wich doubles at each increased step. And accepts general strings as input.

##Goal

Fun.

## Build

Just run `make all`. There are no dependencies. If that does not work try `sudo make all`.
