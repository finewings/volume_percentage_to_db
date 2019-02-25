#include <stdlib.h>
#include <stdio.h>
#define _GNU_SOURCE
#include <math.h>

// Percentage to dB
// min:  		Minimum volume in dB
// max:  		Maximum volume in dB
// percentage:	Percentage of volume. Between 0 ~ 100
double volume_percentage_to_db(
	double min, 			
	double max,			
	int percentage				
	)
{
	double min_norm = exp10((min - max) / 60.0);
	double val_norm = min_norm +  (1 - min_norm) * percentage / 100;
	double value = max + 60.0 * log10(val_norm);
	return value;
}

// dB to percentage
// min:  		Minimum volume in dB
// max:  		Maximum volume in dB
// value:		Volume in dB. Between min ~ max
int volume_db_to_percentage(
	double min, 
	double max, 
	double value
	)
{
	double min_norm = exp10((min - max) / 60.0);
	double val_norm = exp10((value - max) / 60.0);
	int percent = rint((val_norm - min_norm) * 100 / (1 - min_norm));	
	return percent;
}

int main(int argc, char **argv)
{
	if (argc > 3)
	{
		double min = strtod(argv[1], (char **)NULL);
		double max = strtod(argv[2], (char **)NULL);
		int percentage = strtol(argv[3], (char **)NULL, 0);
		
		double val = volume_percentage_to_db(min, max, percentage);
		int percent_inv = volume_db_to_percentage(min, max, val);
		printf("Volume [%.2f ~ %.2f dB] %d%% ==> %.2f dB (%d%%)\n", min, max, percentage, val, percent_inv); 
	}
	else
	{
		printf("Usage: test min_db max_db percentage\n");
	}
}
