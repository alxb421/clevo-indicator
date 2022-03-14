#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int get_cpu_temp();
int get_fan_duty();
int auto_set();
int profile_default();
int profile_quiet();
int profile_nightmode();
int profile_extraperformance();
int start();

int duty = 0;
int temp = 0;
int newduty = 0;

char s_fanduty[4096];
char s_cputemp[4096];

int main( int argc, char *argv[] ) {

if(geteuid() != 0)
{
  printf("Operation not permitted! Run as root\n");
  return EXIT_FAILURE;
}

/*
FILE *governor_file;
governor_file = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor", "w+");
fprintf(governor_file, "performance");
fputs("This is testing for fputs...\n", governor_file);
fclose(governor_file);
*/
 start();

if(argc < 2 ) {
    printf("Select a profile using:\n  --default     | default profile\n  --quiet       | quiet fans\n  --night-mode  | the most silent profile\n  --performance | loudest/coolest profile\n");
    } else {

    if(strcmp(argv[1],"--default")==0) {
        profile_default();
    } else if(strcmp(argv[1],"--quiet")==0) {
        profile_quiet();
    } else if(strcmp(argv[1],"--night-mode")==0){
        profile_nightmode();
    } else if(strcmp(argv[1],"--performance")==0){
        profile_extraperformance();
    } else {
        printf("Select a profile using:\n  --default     | default profile\n  --quiet       | quiet fans\n  --night-mode  | the most silent profile\n  --performance | loudest/coolest profile\n");
        }
    }
    return EXIT_SUCCESS;
}

//getting TEMP in an integer variable
int get_cpu_temp() {
  FILE *command;
  command = popen("/usr/bin/sudo /usr/share/cyrex/modules/fan-control/cyrex-fancontrol --temp", "r");
  while (fgets(s_cputemp, sizeof(s_cputemp), command) != NULL) {
  }
  temp = atoi(s_cputemp);
  pclose(command);
  return 0;
}


//getting FAN DUTY in an integer variable
int get_fan_duty() {
  FILE *command;
  command = popen("/usr/bin/sudo /usr/share/cyrex/modules/fan-control/cyrex-fancontrol --fan-duty", "r");
  while (fgets(s_fanduty, sizeof(s_fanduty), command) != NULL) {
  }
  duty = atoi(s_fanduty);
  pclose(command);
  return 0;
}

int start() {
    printf("Sleeping 1.15s . . .\n");
    sleep(1.15);
    printf("Slept\n");
    get_cpu_temp();
    get_fan_duty();
}


int profile_default() {
for(;;) {
	sleep(0.10);
    if (temp >= 95 && duty < 100) {
        newduty = 100; }
    if (temp >= 90 && duty < 90) {
        newduty = 90; }
    if (temp >= 85 && duty < 75) {
        newduty = 75; }
    if (temp >= 80 && duty < 65) {
        newduty = 65; }
    if (temp >= 75 && duty < 57) {
        newduty = 57; }
    if (temp >= 70 && duty < 50) {
        newduty = 50; }
    if (temp >= 65 && duty < 38) {
        newduty = 38; }
    if (temp >= 60 && duty < 33) {
        newduty = 33; }
    if (temp >= 55 && duty < 26) {
        newduty = 26; }
    if (temp >= 50 && duty < 23) {
        newduty = 23; }
    if (temp >= 45 && duty < 20) {
        newduty = 20; }
//
    if (temp <= 44 && duty > 0) {
        newduty = 0; }
    if (temp <= 45 && duty > 20) {
        newduty = 20; }
    if (temp <= 50 && duty > 23) {
        newduty = 23; }
    if (temp <= 55 && duty > 26) {
        newduty = 26; }
    if (temp <= 60 && duty > 33) {
        newduty = 33; }
    if (temp <= 65 && duty > 38) {
        newduty = 38; }
    if (temp <= 70 && duty > 50) {
        newduty = 50; }
    if (temp <= 75 && duty > 57) {
        newduty = 57; }
    if (temp <= 80 && duty > 65) {
        newduty = 65; }
    if (temp <= 85 && duty > 75) {
        newduty = 75; }
    if (temp <= 90 && duty > 90) {
        newduty = 90; }
    if (temp <= 95 && duty > 100) {
        newduty = 100; }
	start();
		//////////////////////////////////////
		FILE * proc;
		char command[70];
		int len;
		len = snprintf(command, sizeof(command), "/usr/share/cyrex/modules/fan-control/cyrex-fancontrol %d",newduty);
		if (len <= sizeof(command))
		{
		    proc = popen(command, "r");
		}
		//////////////////////////////////////
	}
  return 0;
}

int profile_quiet() {
for (;;) {
    if (temp >= 95 && duty < 100) {
        newduty = 100; }
    if (temp >= 90 && duty < 85) {
        newduty = 85; }
    if (temp >= 85 && duty < 70) {
        newduty = 70; }
    if (temp >= 80 && duty < 60) {
        newduty = 60; }
    if (temp >= 75 && duty < 45) {
        newduty = 45; }
    if (temp >= 70 && duty < 33) {
        newduty = 33; }
    if (temp >= 65 && duty < 25) {
        newduty = 25; }
    if (temp >= 50 && duty < 20) {
        newduty = 20; }
//
    if (temp <= 49 && duty > 0) {
        newduty = 0; }
    if (temp <= 50 && duty > 20) {
        newduty = 20; }
    if (temp <= 65 && duty > 25) {
        newduty = 25; }
    if (temp <= 70 && duty > 33) {
        newduty = 33; }
    if (temp <= 75 && duty > 45) {
        newduty = 45; }
    if (temp <= 80 && duty > 60) {
        newduty = 60; }
    if (temp <= 85 && duty > 70) {
        newduty = 70; }
    if (temp <= 90 && duty > 85) {
        newduty = 85; }
    if (temp <= 95 && duty > 100) {
        newduty = 100; }
	start();
//////////////////////////////////////
FILE * proc;
char command[70];
//char a[]="Encrypted data";
int len;
len = snprintf(command, sizeof(command), "/usr/share/cyrex/modules/fan-control/cyrex-fancontrol %d",newduty);
if (len <= sizeof(command))
{
    proc = popen(command, "r");
}

//////////////////////////////////////
	}
  return 0;

}


int profile_nightmode() {
for (;;) {
    if (temp >= 95 && duty < 100) {
        newduty = 100; }
    if (temp >= 90 && duty < 90) {
        newduty = 90; }
    if (temp >= 85 && duty < 65) {
        newduty = 65; }
    if (temp >= 80 && duty < 55) {
        newduty = 55; }
    if (temp >= 75 && duty < 40) {
        newduty = 40; }
    if (temp >= 70 && duty < 70) {
        newduty = 30; }
    if (temp >= 65 && duty < 25) {
        newduty = 25; }
    if (temp >= 60 && duty < 20) {
        newduty = 20; }
//
    if (temp <= 59 && duty > 0) {
        newduty = 0; }
    if (temp <= 60 && duty > 20) {
        newduty = 20; }
    if (temp <= 65 && duty > 25) {
        newduty = 25; }
    if (temp <= 70 && duty > 70) {
        newduty = 30; }
    if (temp <= 75 && duty > 40) {
        newduty = 40; }
    if (temp <= 80 && duty > 55) {
        newduty = 55; }
    if (temp <= 85 && duty > 65) {
        newduty = 65; }
    if (temp <= 90 && duty > 90) {
        newduty = 90; }
    if (temp <= 95 && duty > 100) {
        newduty = 100; }
	start();
//////////////////////////////////////
FILE * proc;
char command[70];
//char a[]="Encrypted data";
int len;
len = snprintf(command, sizeof(command), "/usr/share/cyrex/modules/fan-control/cyrex-fancontrol %d",newduty);
if (len <= sizeof(command))
{
    proc = popen(command, "r");
}

//////////////////////////////////////
	}
  return 0;
}

int profile_extraperformance() {
for (;;) {
    if (temp >= 90 && duty < 90) {
        newduty = 90; }
    if (temp >= 85 && duty < 80) {
        newduty = 80; }
    if (temp >= 80 && duty < 70) {
        newduty = 70; }
    if (temp >= 75 && duty < 60) {
        newduty = 60; }
    if (temp >= 70 && duty < 50) {
        newduty = 50; }
    if (temp >= 65 && duty < 50) {
        newduty = 50; }
    if (temp >= 60 && duty < 40) {
        newduty = 40; }
    if (temp >= 55 && duty < 40) {
        newduty = 40; }
    if (temp >= 40 && duty < 30) {
        newduty = 30; }
    if (temp >= 30 && duty < 30) {
        newduty = 30; }
    if (temp >= 20 && duty < 16) {
        newduty = 16; }
//
    if (temp <= 19 && duty > 16) {
        newduty = 16; }
    if (temp <= 20 && duty > 16) {
        newduty = 16; }
    if (temp <= 30 && duty > 30) {
        newduty = 30; }
    if (temp <= 40 && duty > 30) {
        newduty = 30; }
    if (temp <= 55 && duty > 40) {
        newduty = 40; }
    if (temp <= 60 && duty > 40) {
        newduty = 40; }
    if (temp <= 65 && duty > 50) {
        newduty = 50; }
    if (temp <= 70 && duty > 50) {
        newduty = 50; }
    if (temp <= 75 && duty > 60) {
        newduty = 60; }
    if (temp <= 80 && duty > 70) {
        newduty = 70; }
    if (temp <= 85 && duty > 80) {
        newduty = 80; }
    if (temp <= 90 && duty > 90) {
        newduty = 90; }
	start();

//////////////////////////////////////
FILE * proc;
char command[70];
//char a[]="Encrypted data";
int len;
len = snprintf(command, sizeof(command), "/usr/share/cyrex/modules/fan-control/cyrex-fancontrol %d",newduty);
if (len <= sizeof(command))
{
    proc = popen(command, "r");
}

//////////////////////////////////////
	}
  return 0;
}

/*
int set_performance() {
        FILE *governor_file;
        governor_file = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor", "w+");
        fprintf(governor_file, "performance");
        fputs("performance", governor_file);
        fclose(governor_file);

        FILE *max_freq;
        max_freq = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq", "w+");
        fprintf(max_freq, "");
        fputs("", max_freq);
        fclose(governor_file);

        FILE *min_freq;
        min_freq = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq", "w+");
        fprintf(min_freq, "400000");
        fputs("400000", min_freq);
        fclose(governor_file);

}


int set_powesave() {
        FILE *governor_file;
        governor_file = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor", "w+");
        fprintf(governor_file, "powersave");
        fputs("powersave", governor_file);
        fclose(governor_file);


        FILE *max_freq;
        max_freq = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq", "w+");
        fprintf(max_freq, "");
        fputs("", max_freq);
        fclose(governor_file);

        FILE *min_freq;
        min_freq = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq", "w+");
        fprintf(min_freq, "400000");
        fputs("400000", min_freq);
        fclose(governor_file);

}


int set_balanced() {
        FILE *governor_file;
        governor_file = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor", "w+");
        fprintf(governor_file, "performance");
        fputs("performance", governor_file);
        fclose(governor_file);

	FILE *max_freq;
	max_freq = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq", "w+");
	fprintf(max_freq, "");
	fputs("", max_freq);
	fclose(governor_file);

        FILE *min_freq;
        min_freq = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq", "w+");
        fprintf(min_freq, "400000");
        fputs("400000", min_freq);
        fclose(governor_file);

}
*/
