#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * @brief 	Convert volume in percentage to volume in dB.
 *
 * @param min	  		Minimum volume in dB.
 * @param max  			Maximum volume in dB.
 * @param percentage	Volume in dB. Between min ~ max.
 *
 * @return		Return volume in dB
 */
double volume_percentage_to_db(
	double min, 			
	double max,			
	int percentage				
	)
{
	double min_norm = pow(10.0f, (min - max) / 60.0f);
	double val_norm = min_norm +  (1 - min_norm) * percentage / 100;
	double value = max + 60.0f * log10(val_norm);
	return value;
}

/**
 * @brief 	Convert volume in dB to volume in percentage.
 *
 * @param min	  		Minimum volume in dB.
 * @param max	  		Maximum volume in dB.
 * @param value			Volume in dB. Between min ~ max.
 *
 * @return		Return volume in percentage
 */
int volume_db_to_percentage(
	double min, 
	double max, 
	double value
	)
{
	double min_norm = pow(10.0f, (min - max) / 60.0f);
	double val_norm = pow(10.0f, (value - max) / 60.0f);
	int percent = (int)rint((val_norm - min_norm) * 100 / (1 - min_norm));	
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
		printf("Usage: test min_in_dB max_in_dB volume_in_percentage\n");
	}
}
