#include "stats.h"
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    float sum=0;
    float max=0,min=0;
    min=*numberset;
    max=*numberset;
    if(setlength == 0)
    {
        s.average=NAN;
        s.min=NAN;
        s.max=NAN;
    }
    else
    {
        
        for(int i=0;i<=setlength-1;i++)
        {
            sum+=*numberset;
            if(min<*numberset)
                min=*numberset;
            if(max>*numberset)
                max=*numberset;
            
        }
        numberset++;
        s.average=sum/setlength;
        s.min=min;
        s.max=max;
    }
    
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void ledAlerter(void)
{
    
}
void emailAlerter(void)
{
    
}

void check_and_alert(float maxThreshold, alerter_funcptr alert_array[], Stats_t computedStats)
{
	if (computedStats.max > maxThreshold)
	{
		alert_array[0]();
		alert_array[1]();
	}
}
