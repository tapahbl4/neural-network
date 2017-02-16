# Neural network for forecasting exchange rates
*Education work*  
Description  
Description  
Description  

## Configuration file
1 line: layers count N  
2 line: N numbers - neuron count on each layer  
3 line: if next data it's neuron weight then 1 else 0  
i line: synapse count on current neuron M  
i+1 line: M numbers - each neuron weight  

## Compile and launch
Unpack archive and run this commands
$ cd neural-network/core/  
$ make prepare  
$ make  
For launch use  
$ ./bin/nn  
Parameters list:  
-v (--version) - print version and developer  
-h (--help) - print help  
-l (--learn) - launch neural network for learning (required params: -s, -d, -i, -o)  
-t (--test) - testing neural network (required params: -d, -i)  
-p (--process) - processing neural network (required params: -d, -i)  
-i (--input) - input file with scheme (and weights for neurons)  
-o (--output) - output file for learning, testing or processing   result
-d (--data) -  data file for learning, testing or processing neural network  
--iteration - counts of learning iteration (if data file is large)
--log - print info about learning each N iterations  
If you launch without --output, then application will printing in stdout.   
