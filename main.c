    #include <stdio.h>
    #include <stdlib.h>
    #include<string.h>
    void calculate(int score[][6],int n,int subject);
    float aver[6];
    int total_stu[30],total_sub[6];
    //�������мǵû�����
    void descending(int score[30],int num[],int n,char name[][15]);
    //����
    void swap(int *x,int *y);
    //��ӡ
    void print(int a[],int b[],int n,char name[][15]);
    //���ɼ���������
    void ascending(int score[30],int num[],int n,char name[][15]);
    //��ѧ����������
    void ascending_num(int score[][6],int num[],int n,char name[][15],int subject);
    //��ѧ��Ѱ�ҳɼ�����ӡ
    void search(int number,int num[],int score[][6],int n ,char name[][15],int subject);
    //�����ɼ����
    void analysis(int score[][6],int n,int subject);
    //��¼��ʼ�ɼ�����
    void record(int *x,int (*y)[6],char (*z)[],int num[],int score[][6],int n,char name[][15],int subject);
    //����������
    void ascending_name(int score[][6],int num[],int n,char name[][15],int subject);
    //�����ֲ�ɼ�
    void search_name(char putname[],int score[][6],int num[],int n,char name[][15],int subject);
    void calculate_stu(int score[][6],int n,int subject,char name[][15]);
    void swap_score(int *p,int *q,int subject);
    int main()
    {
        //ѧ�ţ��ɼ�������  num_record[30],score_record[30] ��¼��ʼ�������
        int  num[30],score[30][6],n,num_record[30],score_record[30][6];
        char name[30][15],name_record[30][15],putname[15];
        int choice,i,number,subject,j;
        //��ʾ�˵�
        do
        {
            //����choice����ֹchoice�������
            do
            {
            printf("1. Input record\n2. Calculate total and average score of every course\n3. Calculate total and average score of every student\n4. Sort in descending order by total score of every student\n5. Sort in ascending order by total score of every student\n6. Sort in ascending order by number\n");
            printf("7. Sort in dictionary order by name\n8. Search by number\n9. Search by name\n10.Statistic analysis for every course\n11.List record\n0. Exit\nPlease enter your choice:");
            scanf("%d",&choice);
            }while(choice>11||choice<0);
            //����choice������ѡ��
            switch(choice)
            {
            //����
            case 1:
            {
                do
                {
                    printf("input student number:\n");
                    scanf("%d",&n);
                }while(n<=0||n>30);
                do
                {
                    printf("input subject number:\n");
                    scanf("%d",&subject);
                }while(subject<=0||subject>6);


                for(i=0; i<n; i++)
                {
                    printf("input number and name and all %d subject score:\n",subject);//����ѧ�źͳɼ�
                    printf("this is student %d\n",i+1);
                    printf("number: ");
                    scanf("%d",&num[i]);
                    getchar();//��ȥ�س�
                    printf("name: ");
                     gets(name[i]);

                    for(j=0;j<subject;j++)
                    {
                        printf("subject %d:",j+1);
                        scanf("%d",&score[i][j]);

                    }
                }
                record(num_record,score_record,name_record,num,score,n,name,subject);


                break;
            }
            //���ֺܷ�ƽ����
            case 2:
            {
                calculate(score,n,subject);
                for(i=0;i<subject;i++)
                     printf("subject %d:  total=%d,aver=%f\n",i+1,total_sub[i],aver[i]);
                break;
            }
            //ѧ��ƽ�����ܷ�
            case 3:
            {
                 calculate_stu(score ,n,subject,name);
                 break;
            }
            //����
            case 4:
            {
                descending( total_stu, num, n,name);
                print(num,total_stu,n,name);
                break;
            }
            //����
            case 5:
            {
                ascending(total_stu,num,n,name);
                print(num,total_stu,n,name);
                break;
            }
            //ѧ������
            case 6:
            {
                ascending_num(score,num,n,name,subject);
                break;
            }
            //��������
            case 7:
                {
                    ascending_name(score,num,n,name,subject);

                    break;
                }
            //ѧ�Ų�ɼ�
            case 8:
            {
                printf("please input the number:\n");
                scanf("%d",&number);
                search(number,num,score,n,name,subject);
                break;
            }
            //������ɼ�
            case 9:
                {
                    printf("please input the name:\n");
                    getchar();
                    gets(putname);
                    search_name(putname,score,num,n,name,subject);
                    break;

                }
            //�ɼ�����
            case 10:
            {
                analysis(score,n,subject);
                break;
            }
            //��ʼ˳���ӡ,�γ��ܷ֣�ƽ����
            case 11:
            {
                for(i=0; i<n; i++)
        {
             printf("%5d\t%s\t",num_record[i],name_record[i]);
            for(j=0;j<subject;j++)
                printf("%5d\t",score_record[i][j]);
                printf("\n");
        }
             calculate(score,n,subject);
            for(j=0,i=0;j<subject;j++,i++)
            {
                printf("subject %d:  total=%d,aver=%f\n",i+1,total_sub[i],aver[i]);
            }

                break;
            }
            }
        }
        //ֱ������11�˳�
        while(choice!=0);
    }

    void calculate(int score[][6],int n,int subject)
    {
        int i=0,j=0;

        for(i=0; i<subject; i++)
        {
            for(j=0;j<n;j++)
            total_sub[i]=total_sub[i]+score[j][i];
            aver[i]=(float)total_sub[i]/n;

        }
        }


    void descending(int score[30],int num[],int n,char name[][15])
    {
        int i,j,k;
        char temp[15];
        for(i=0; i<n-1; i++)
        {
            k=i;
            for(j=i+1; j<n; j++)
            {
                if(score[k]<score[j])
                    k=j;
            }
            if(k!=i)
            {
                swap(&score[k],&score[i]);
                swap(&num[k],&num[i]);
                strcpy(temp,name[k]);
                strcpy(name[k],name[i]);
                strcpy(name[i],temp);

            }
        }

    }

    void swap(int *x,int *y)
    {
        int temp;
        temp=*x;
        *x=*y;
        *y=temp;

    }

    void print(int a[],int b[],int n,char name[][15])
    {
        int i;
        for(i=0; i<n; i++)
        {
            printf("%5d\t%s\t%5d\t\n",a[i],name[i],b[i]);
        }
    }

    void ascending(int score[30],int num[],int n,char name[][15])
    {
        int i,j,k;
        char temp[15];
        for(i=0; i<n-1; i++)
        {
            k=i;
            for(j=i+1; j<n; j++)
            {
                if(score[k]>score[j])
                    k=j;
            }
            if(k!=i)
            {
                swap(&score[k],&score[i]);
                swap(&num[k],&num[i]);
                strcpy(temp,name[k]);
                strcpy(name[k],name[i]);
                strcpy(name[i],temp);

            }
        }

    }

    void ascending_num(int score[][6],int num[],int n,char name[][15],int subject)
    {
        int i,j,k;
        char temp[15];
        for(i=0; i<n-1; i++)
        {
            k=i;
            for(j=i+1; j<n; j++)
            {
                if(num[k]>num[j])
                    k=j;
            }
            if(k!=i)
            {
                swap_score(&score[k][0],&score[i][0],subject);
                swap(&num[k],&num[i]);
                strcpy(temp,name[k]);
                strcpy(name[k],name[i]);
                strcpy(name[i],temp);

            }
        }
        printf("num\tname\t");
        for(i=0;i<subject;i++)
        {
            printf("subject %d\t",i+1);
        }
        printf("\n");
        for(i=0; i<n; i++)
        {
             printf("%5d\t%s\t",num[i],name[i]);
            for(j=0;j<subject;j++)
                printf("%5d\t\t",score[i][j]);
                printf("\n");
        }
    }

    void swap_score(int *p,int *q,int subject)
    {
        int temp,i;
        for(i=0;i<subject;i++)
        {
            temp=*(p+i);
            *(p+i)=*(q+i);
            *(q+i)=temp;
        }
    }

    void search(int number,int num[],int score[][6],int n,char name[][15],int subject)
    {
                int i,count=0,j;

                  for(i=0; i<n; i++)
                {
                        if(num[i]==number)
                        {

                        printf("%d\t%s\t",num[i],name[i]);
                        for(j=0;j<subject;j++)
                        printf("%5d\t",score[i][j]);
                        printf("\n");
                        count++;
                    }

                }
                if(count==0)
                    {
                        printf("input wrong number!!\n");
                    }


        }

    void analysis(int score[][6],int n,int subject)
    {
        int i,A=0,B=0,C=0,D=0,E=0,j;
        for(j=0;j<subject;j++)
        {
            A=0,B=0,C=0,D=0,E=0;
        for(i=0; i<n; i++)
        {
            if(score[i][j]>=90)
                A++;
            if(score[i][j]<90&&score[i][j]>=80)
            {
                B++;
            }
            if(score[i][j]<80&&score[i][j]>=70)
            {
                C++;
            }
            if(score[i][j]<70&&score[i][j]>=60)
            {
                D++;
            }
            if(score[i][j]<60)
                E++;
        }
        printf("subjet %d :\n",j+1);
        printf("����  %3d   %f%%\n����  %3d   %f%%\n�е�  %3d   %f%%\n����  %3d   %f%%\n������ %2d   %f%%\n",A,100*(float)A/n,B,100*(float)B/n,C,100*(float)C/n,D,100*(float)D/n,E,100*(float)E/n);
        }
    }

    void record(int *x,int (*y)[6],char (*z)[15],int num[],int score[][6],int n,char name[][15],int subject)
    {
        int i,j;

        for(i=0;i<n;i++,x++,z++)
        {
            *x=num[i];

            strcpy(*z,name[i]);


        }
        for(i=0;i<n;i++,y++)
        {

            for(j=0;j<subject;j++)
            {
                *(*y+j)=score[i][j];
            }
        }
    }
    void ascending_name(int score[][6],int num[],int n,char name[][15],int subject)
    {
        int i,j;
        char temp[15];
        for(i=0;i<n-1;i++)
        {
            for(j=i;j<n;j++)

            {
                if(strcmp(name[j],name[i])<0)
                {
                strcpy(temp,name[j]);
                strcpy(name[j],name[i]);
                strcpy(name[i],temp);
                swap_score(&score[j][0],&score[i][0],subject);
                swap(&num[j],&num[i]);
                }
            }
        }
         printf("num\tname\t");
        for(i=0;i<subject;i++)
        {
            printf("subject %d\t",i+1);
        }
        printf("\n");
        for(i=0; i<n; i++)
        {
             printf("%5d\t%s\t",num[i],name[i]);
            for(j=0;j<subject;j++)
                printf("%5d\t\t",score[i][j]);
                printf("\n");
        }

    }
    void search_name(char putname[],int score[][6],int num[],int n,char name[][15],int subject)
    {
        int i,count=0,j;

        for(i=0;i<n;i++)
        {
            if(strcmp(putname,name[i])==0)
            {
                printf("%5d\t%s\t",num[i],name[i]);
                for(j=0;j<subject;j++)
                printf("%3d\t",score[i][j]);
                printf("\n");
                count++;
            }
        }
        if(count==0)
        printf("input wrong name!!\n");

    }
    void calculate_stu(int score[][6],int n,int subject,char name[][15])
    {
         int i=0,j=0;

        for(i=0; i<n; i++)
        {
            for(j=0;j<subject;j++)
            total_stu[i]=total_stu[i]+score[i][j];
            aver[i]=(float)total_stu[i]/n;
            printf("student %s:  total=%d,aver=%f\n",name[i],total_stu[i],aver[i]);
        }
    }
