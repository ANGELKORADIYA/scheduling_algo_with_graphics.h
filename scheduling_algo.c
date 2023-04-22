#include <stdio.h>
#include <string.h>
#include <graphics.h>
void fcfs(int total, int *P, int *AT, int *BT, int *FT)
{
    int time = 0, temp, tempP;

    int gd = DETECT, gm;
    int timeMagnifire = 1;
    initgraph(&gd, &gm, NULL);
    int y1 = 100, y2 = 200;
    int x1 = 50;
    int timeprevious = x1;
    int abt = 0;
    for (int i = 0; i < total; i++)
    {
        abt += BT[i];
    }
    if (abt <= total * 20)
    {
        timeMagnifire = 10;
    }

    for (int j = 0; j < total; j++)
    {

        for (int i = 0; i < total; i++)
        {
            if (FT[i] == 0)
            {
                temp = AT[i];
                tempP = i;
                break;
            }
        }
        for (int i = 0; i < total; i++)
        {
            if (temp > AT[i] && FT[i] == 0)
            {
                temp = AT[i];
                tempP = i;
            }
        }
        if (time < temp)
        {
            time = temp;
        }
        time += BT[tempP];
        FT[tempP] = time;

        line((time)*timeMagnifire + 50, y1, (time)*timeMagnifire + 50, y2);
        char output[50];
        sprintf(output, "%d", time);
        outtextxy((time)*timeMagnifire + 50, y2 + 10, output);
        sprintf(output, "%d", P[tempP]);
        char output2[50] = "P";
        strcat(output2, output);
        outtextxy(((((time)*timeMagnifire) + 50) + timeprevious) / 2, (y1 + y2) / 2, output2);
        timeprevious = (time * timeMagnifire) + 50;
    }

    int x2 = (time)*timeMagnifire + 50;
    line(x1, y1, x2, y1);
    line(x1, y2, x2, y2);
    line(50, y1, 50, y2);
    char output[] = "0";
    outtextxy(50, y2 + 10, output);
}
void PRIONON(int total, int *P, int *AT, int *BT, int *FT, int *PRIO)
{

    int time = 0, temp, tempB, tempP;
    int gd = DETECT, gm;
    int timeMagnifire = 1;
    initgraph(&gd, &gm, NULL);
    int y1 = 100, y2 = 200;
    int x1 = 50;
    int timeprevious = x1;
    int abt = 0;
    for (int i = 0; i < total; i++)
    {
        abt += BT[i];
    }
    if (abt <= total * 20)
    {
        timeMagnifire = 10;
    }
    for (int j = 0; j < total; j++)
    {
        int tempO[total];
        for (int i = 0; i < total; i++)
        {
            tempO[i] = -1;
        }
        int count = 0;

        for (int i = 0; i < total; i++)
        {
            if (FT[i] == 0)
            {
                temp = AT[i];
                tempP = i;
                tempB = BT[i];
                break;
            }
        }
        for (int i = 0; i < total; i++)
        {
            if (time >= AT[i] && FT[i] == 0)
            {
                tempO[count] = i;
                count++;
            }
            else if (temp >= AT[i] && FT[i] == 0)
            {
                tempO[count] = i;
                count++;
            }
        }
        // for (int i = 0; i < total; i++)
        // {
        //     printf("%d\n", tempO[i]);
        // }
        int x, xB;
        if (tempO[1] != -1)
        {
            x = tempO[0];
            xB = PRIO[tempO[0]];
            for (int i = 0; i < count; i++)
            {
                if (xB >= PRIO[tempO[i]])
                {
                    temp = AT[tempO[i]];
                    tempP = tempO[i];
                    tempB = PRIO[tempO[i]];
                    int xp = x, xBp = xB;
                    x = tempO[i];
                    xB = PRIO[tempO[i]];
                    if (xBp == xB)
                    {
                        if (BT[xp] < BT[x])
                        {
                            x = xp;
                            xB = xBp;
                            temp = AT[x];
                            tempP = x;
                            tempB = PRIO[x];
                        }
                    }
                }
            }
        }
        else
        {
            temp = AT[tempO[0]];
            tempP = tempO[0];
            tempB = BT[tempO[0]];
        }

        if (time < temp)
        {
            time = temp;
        }
        time += BT[tempP];
        FT[tempP] = time;

        line((time)*timeMagnifire + 50, y1, (time)*timeMagnifire + 50, y2);
        char output[50];
        sprintf(output, "%d", time);
        outtextxy((time)*timeMagnifire + 50, y2 + 10, output);
        sprintf(output, "%d", P[tempP]);
        char output2[50] = "P";
        strcat(output2, output);
        outtextxy(((((time)*timeMagnifire) + 50) + timeprevious) / 2, (y1 + y2) / 2, output2);
        timeprevious = (time * timeMagnifire) + 50;
    }
    int x2 = (time)*timeMagnifire + 50;
    line(x1, y1, x2, y1);
    line(x1, y2, x2, y2);
    line(50, y1, 50, y2);
    char output[] = "0";
    outtextxy(50, y2 + 10, output);
}
void sjf(int total, int *P, int *AT, int *BT, int *FT)
{
    int gd = DETECT, gm;
    int timeMagnifire = 1;
    initgraph(&gd, &gm, NULL);
    int y1 = 100, y2 = 200;
    int x1 = 50;
    int timeprevious = x1;
    int abt = 0;
    for (int i = 0; i < total; i++)
    {
        abt += BT[i];
    }
    if (abt <= total * 20)
    {
        timeMagnifire = 10;
    }

    int time = 0, temp, tempB, tempP;
    int BTtemp[total];
    for (int i = 0; i < total; i++)
    {
        BTtemp[i] = BT[i];
    }
    while (1)
    {
        int tempO[total];
        for (int i = 0; i < total; i++)
        {
            tempO[i] = -1;
        }
        int count = 0;
        for (int i = 0; i < total; i++)
        {
            if (FT[i] == 0)
            {
                temp = AT[i];
                tempP = i;
                tempB = BT[i];
                break;
            }
        }
        for (int i = 0; i < total; i++)
        {
            if (time >= AT[i] && FT[i] == 0)
            {
                tempO[count] = i;
                count++;
            }
            else if (temp >= AT[i] && FT[i] == 0)
            {
                tempO[count] = i;
                count++;
            }
        }
        int x, xB;
        if (tempO[1] != -1)
        {
            x = tempO[0];
            xB = BT[tempO[0]];
            for (int i = 0; i < count; i++)
            {
                if (xB > BT[tempO[i]])
                {
                    temp = AT[tempO[i]];
                    tempP = tempO[i];
                    x = tempO[i];
                    tempB = BT[tempO[i]];
                    xB = BT[tempO[i]];
                }
            }
        }
        else
        {
            temp = AT[tempO[0]];
            tempP = tempO[0];
            tempB = BT[tempO[0]];
        }

        // for (int i = 0; i < total; i++)
        // {
        //     printf("%d\n", tempO[i]);
        // }
        
        // for (int i = 0; i < total; i++)
        // {
        //     printf("%12d | %12d | %12d | %12d \n", P[i], AT[i], BT[i], FT[i]);
        // }
        if (tempO[0] == -1)
        {
            break;
        }
        if (time < temp)
        {
            time = temp;
        }
        time += BT[tempP];
        FT[tempP] = time;
        line((time)*timeMagnifire + 50, y1, (time)*timeMagnifire + 50, y2);
        char output[50];
        sprintf(output, "%d", time);
        outtextxy((time)*timeMagnifire + 50, y2 + 10, output);
        sprintf(output, "%d", P[tempP]);
        char output2[50] = "P";
        strcat(output2, output);
        outtextxy(((((time)*timeMagnifire) + 50) + timeprevious) / 2, (y1 + y2) / 2, output2);
        timeprevious = (time * timeMagnifire) + 50;
        
    }
    int x2 = (time)*timeMagnifire + 50;
    line(x1, y1, x2, y1);
    line(x1, y2, x2, y2);
    line(50, y1, 50, y2);
    char output[] = "0";
    outtextxy(50, y2 + 10, output);
    
}
void srtn(int total, int *P, int *AT, int *BT, int *FT)
{
    int BTtemp[total];
    for (int i = 0; i < total; i++)
    {
        BTtemp[i] = BT[i];
    }

    int time = 0, temp, tempB, tempP;

    int gd = DETECT, gm;
    int timeMagnifire = 1;
    initgraph(&gd, &gm, NULL);
    int y1 = 100, y2 = 200;
    int x1 = 50;
    int timeprevious = x1;
    int abt = 0;
    // int atempP=-1;
    for (int i = 0; i < total; i++)
    {
        abt += BT[i];
    }
    if (abt <= total * 20)
    {
        timeMagnifire = 30;
    }

    while (1)
    {
        int tempO[total];
        for (int i = 0; i < total; i++)
        {
            tempO[i] = -1;
        }
        int count = 0;

        for (int i = 0; i < total; i++)
        {
            if (FT[i] == 0)
            {
                temp = AT[i];
                tempP = i;
                tempB = BT[i];
                break;
            }
        }
        for (int i = 0; i < total; i++)
        {
            if (time >= AT[i] && FT[i] == 0)
            {
                tempO[count] = i;
                count++;
            }
            else if (temp >= AT[i] && FT[i] == 0)
            {
                tempO[count] = i;
                count++;
            }
        }
        // for (int i = 0; i < total; i++)
        // {
        //     printf("%d\n", tempO[i]);
        // }
        int x, xB;
        if (tempO[1] != -1)
        {
            x = tempO[0];
            xB = BT[tempO[0]];
            for (int i = 0; i < count; i++)
            {
                if (xB > BT[tempO[i]])
                {
                    temp = AT[tempO[i]];
                    tempP = tempO[i];
                    tempB = BT[tempO[i]];
                    x = tempO[i];
                    xB = BT[tempO[i]];
                }
            }
        }
        else
        {
            temp = AT[tempO[0]];
            tempP = tempO[0];
            tempB = BT[tempO[0]];
        }

     
        if (tempO[0] == -1)
        {
            break;
        }
           if (time < temp){
            time = temp; //no idea
        }
        time++;
        BTtemp[tempP]--;
        if (BTtemp[tempP] == 0)
        {
            FT[tempP] = time;
        }
        // for(int i = 0; i < total; i++)
        // {
        //     printf("%12d | %12d | %12d | %12d \n", P[i], AT[i], BT[i], FT[i]);
        // }
        // if(atempP!=tempP||atempP==-1){
        line((time)*timeMagnifire + 50, y1, (time)*timeMagnifire + 50, y2);
        char output[50];
        sprintf(output, "%d", time);
        outtextxy((time)*timeMagnifire + 50, y2 + 10, output);
        sprintf(output, "%d", P[tempP]);
        char output2[50] = "P";
        strcat(output2, output);
        outtextxy(((((time)*timeMagnifire) + 50) + timeprevious) / 2, (y1 + y2) / 2, output2);
        timeprevious = (time * timeMagnifire) + 50;
        // }
        // atempP=tempP;
    }
    int x2 = (time)*timeMagnifire + 50;
    line(x1, y1, x2, y1);
    line(x1, y2, x2, y2);
    line(50, y1, 50, y2);
    char output[] = "0";
    outtextxy(50, y2 + 10, output);
}

void printt(int total, int *P, int *AT, int *BT, int *FT, int *TAT, int *WA, float *ATAT, float *AWA)
{
    {
        printf("-----------------------\nOutput:-");
        printf("\n%12s | %12s | %12s | %12s | %16s | %12s \n", "Process Name", "Arrival Time", "Burst Time", "Finish Time", "Turn Around Time", "Waiting Time");
        for (int i = 0; i < total; i++)
        {
            TAT[i] = FT[i] - AT[i];
            *ATAT += TAT[i];
            WA[i] = TAT[i] - BT[i];
            *AWA += WA[i];
            printf("%12d | %12d | %12d | %12d | %16d | %12d \n", P[i], AT[i], BT[i], FT[i], TAT[i], WA[i]);
        }
        *ATAT = *ATAT / total;
        *AWA = *AWA / total;
        printf("-----------------------\n");
        printf("Average Turn Around Time :- %f\nAverage Waiting Time :- %f", *ATAT, *AWA);
    }
}
void printtt(int total, int *P, int *AT, int *BT, int *FT, int *TAT, int *WA, float *ATAT, float *AWA, int *PRIO)
{
    {
        printf("-----------------------\nOutput:-");
        printf("\n%12s | %12s | %12s | %12s | %12s | %16s | %12s \n", "Process Name", "Arrival Time", "Burst Time", "Proirity", "Finish Time", "Turn Around Time", "Waiting Time");
        for (int i = 0; i < total; i++)
        {
            TAT[i] = FT[i] - AT[i];
            *ATAT += TAT[i];
            WA[i] = TAT[i] - BT[i];
            *AWA += WA[i];
            printf("%12d | %12d | %12d | %12d | %12d | %16d | %12d \n", P[i], AT[i], BT[i], PRIO[i], FT[i], TAT[i], WA[i]);
        }
        *ATAT = *ATAT / total;
        *AWA = *AWA / total;
        printf("-----------------------\n");
        printf("Average Turn Around Time :- %f\nAverage Waiting Time :- %f", *ATAT, *AWA);
    }
}

int main()
{
    int total;
    int select;
    printf("Choose the Scheduing Alogorithem (Enter Number of it):-\n1.FCFS\n2.SJF(non-preamtive)\n3.SRTN\n4.Priority(non-preamtive)\n5.Priority(preamtive)\n6.Round Robing\n");
    scanf("%d", &select);
    printf("How much Process you want? :- ");
    scanf("%d", &total);
    int P[total];
    int AT[total];
    int BT[total];
    int FT[total];
    int TAT[total];
    int WA[total];
    int PRIO[total];
    float ATAT = 0, AWA = 0;
    {
        for (int i = 0; i < total; i++)
        {
            FT[i] = 0;
        }

        printf("Enter Process Name , Arrival Time , Burst Time Like this:- 2 2 2 \n");
        printf("-----------------------\n");
        for (int i = 0; i < total; i++)
        {
            printf("Enter %d's Process  Process Name , Arrival Time , Burst Time Like this:- ", i + 1);
            scanf("%d%d%d", &P[i], &AT[i], &BT[i]);
        }
    }
    switch (select)
    {
    case 1:
        fcfs(total, P, AT, BT, FT);
        break;
    case 2:
        sjf(total, P, AT, BT, FT);
        break;
    case 3:
        srtn(total, P, AT, BT, FT);
        break;
    case 4:
        for (int i = 0; i < total; i++)
        {
            printf("Enter %d's Priority :- ", i + 1);
            scanf("%d", &PRIO[i]);
        }
        PRIONON(total, P, AT, BT, FT, PRIO);

        break;
    default:
        break;
    }

    if (select == 4 || select == 5)
    {

        printtt(total, P, AT, BT, FT, TAT, WA, &ATAT, &AWA, PRIO);
    }
    else
    {
        printt(total, P, AT, BT, FT, TAT, WA, &ATAT, &AWA);
    }
    getch();
    closegraph();
    return 0;
}