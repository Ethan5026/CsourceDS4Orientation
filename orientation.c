
#include <stdio.h>
#include <math.h>


double magnitude(double x, double y, double z);
int orientation(double gx, double gy, double gz, int buffer);
int close_to(double tolerance, double point, double value);

// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./orientation


int main(int argc, char *argv[])
{
    int triangle, circle, x_button, square;
    double ax, ay, az, gx, gy, gz;
	int buffer=0;

    while (1)
    {
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
              &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);

		if (magnitude(ax, ay, az) <.2)
			buffer = orientation(gx, gy, gz, buffer);
		if(triangle ==1)
			break;
        
    }

    return 0;
}

double magnitude(double x, double y, double z)
{

   return sqrt( x*x + y*y+z*z);
}

int close_to(double tolerance, double point, double value){

if ((value >(point - tolerance) && (value < (point +tolerance))))
	return 1;
else 
	return 0;
}

int orientation(double gx, double gy, double gz, int buffer){
	 
	 if(close_to(.25,1,gy)){
	 if (buffer !=1){
		 printf("\nTOP\n");
	 buffer = 1;}}
	 else if(close_to(.25,-1,gy)){
		 if(buffer!=2){
		 printf("\nBOTTOM\n");
	 buffer=2;}}
	 else if (close_to(.25, -1, gz)){
		 if(buffer!=3){
		 printf("\nFRONT\n");
	 buffer=3;}}
	 else if(close_to(.25,1,gz)){
		 if(buffer!=4){
		 printf("\nBACK\n");
buffer=4;}}
	 else if(close_to(.25,1,gx)){
		 if (buffer !=5){
		 printf("\nLEFT\n");
	 buffer=5;}}
	 else if(close_to(.25,-1,gx)){
		 if(buffer!=6){
		 printf("\nRIGHT\n");
	 buffer  =6;}}
	 return buffer;
}
		