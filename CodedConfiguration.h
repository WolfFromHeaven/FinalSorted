#ifndef _CMR_CONFIGURATION
#define _CMR_CONFIGURATION

#include "Configuration.h"

class CodedConfiguration : public Configuration {

 private:
  unsigned int load;
  
 public:
 CodedConfiguration(): Configuration() {
    numInput = 2;    // N is assumed to be K choose r     
    numReducer = 2;  // K
    load = 1;        // r    
    
    inputPath = "./Input/file.txt";
		outputPath = "./Outputs/Input10kB";
    partitionPath = "./Partition/Input10kB";
    numSamples = 10000000;    
  }
  ~CodedConfiguration() {}

  unsigned int getNumInput() const { return numInput;}
  unsigned int getLoad() const { return load; }
};

#endif
