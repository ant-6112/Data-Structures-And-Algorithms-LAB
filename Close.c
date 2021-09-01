#include<stdio.h>
#include<math.h>

int count = 0;

struct Point
{
    float x;
    float y;
};

void input(struct Point pts[], unsigned int n)
{
    for(int i = 0;i<n;++i){
        printf("\nFor Point %d:\n", i);
        printf("x =");
        scanf("%f", &(pts[i].x));
        printf("y = ");
        scanf("%f", &(pts[i].y));
    }
}

void print(struct Point pts[],unsigned int n)
{
    for(int i = 0;i<n;++i){
        printf("(%f, %f)\n",pts[i].x,pts[i].y);
    }
}

float edistance(struct Point p1, struct Point p2)
{
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

float ClosestPairDistance(struct Point pts[], unsigned int n)
{
    float mindistance = INFINITY;
    for(int i = 0;i<n-1;++i){
        for(int j = i+1;j<n;j++){
            float dist = edistance(pts[i], pts[j]);
            count++;
            if(mindistance > dist){
                mindistance = dist;
            }
        }
    }
    return mindistance;
}

//If y is Fixed To 'b' then All The Points Will Lie On A Straight Line Y = 'b' and The Closest Pair Distance Between Them Will Be Calculated Based On The Values of X.
//edistance would be Equal To (p1.x - p2.x)

float ClosestPairDistanceSpecialCase(struct Point pts[], unsigned int n)
{
    float mindistance = INFINITY;
    for(int i = 0;i<n-1;++i){
        for(int j = i+1;j<n;j++){
            float dist = abs(pts[i].x - pts[j].x);
            count++;
            if(mindistance > dist){
                mindistance = dist;
            }
        }
    }
    return mindistance;
}


int main(void)
{
    unsigned int n = 0;
    printf("Enter n:");
    scanf("%i", &n);

    struct Point pts[n];
    input(pts,n);
    print(pts,n);
    printf("The Closest Pair Distance is: %lf\n",ClosestPairDistanceSpecialCase(pts,n));
    printf("Total Number Of Times Edistance Is Called: %i\n",count);
}

