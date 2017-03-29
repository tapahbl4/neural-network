# Neural network for forecasting exchange rates
*Education work*   

## Configuration file
1. Layers count **N**  
2. **N** numbers - neuron count on each layer  
3. If next data it's neuron weight then *1* else *0*  
4. **i** line: synapse count on current neuron **M**  
5. **i+1** line: **M** numbers - each neuron weight  

## Compile and launch
Unpack archive and run this commands
```bash
$ cd neural-network/core/  
$ make prepare  
$ make  
```

For launch use
```bash
$ ./bin/nn  
```

####Parameters list
Long               |Short        |Meaning                                                     |Required params
-------------------|-------------|------------------------------------------------------------|-------------------
`--version`        |`-v`         |Print version and developer                                 |None
`--help`           |`-h`         |Print help                                                  |None
`--learn`          |`-l`         |Launch neural network for learning                          |`-s` `-d` `-i` `-o`
`--test`           |`-t`         |Testing neural network                                      |`-d` `-i`
`--process`        |`-p`         |Processing neural network                                   |`-d` `-i`
`--input filename` |`-i filename`|Input file with scheme (and weights for neurons)            |None
`--output filename`|`-o filename`|output file for learning, testing or processing result      |None
`--data filename`  |`-d filename`|Data file for learning, testing or processing neural network|None
`--iteration N`    |None         |Counts of learning iteration (if data file is large)        |None
`--log N`          |None         |Print info about learning each **N** iterations             |None

> If you launch without `--output`, then application will printing in **stdout**.   

## Install frontend
For example, i'm using apache  
Frontend works **without** PHP and DB
```bash
$ cd /path/to/apache2 # Ubuntu: /var/www
$ ln -s /path/to/neural-network
$ chmod o+x neural-network
$ sudo -i
$ echo "\n127.0.0.1 yourdomain.loc" >> /etc/hosts
$ cd /etc/apache2/sites-available/
$ cp 000-default.conf nn-frontend.conf
$ nano nn-frontend.conf
### change domain and destination folder ###
$ systemctl restart apache2
```
