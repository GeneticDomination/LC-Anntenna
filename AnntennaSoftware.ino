//anntenna software con ops
//purpose is to deploy the annetnnas one and to ensure they are deployed properly
//Programmer: Genevieve Cooper, Jaime Dela Vega, Christopher McCormick

void setup() 
{    
  
}

void loop() 
{  
  if (D2 && D3 == HIGH) //are positive
    Deploy_A();
  if()
}
bool Deploy_A()
  {
    //deplays A doors
    //when flight software call deploy then 
    //want to deploy sequencially, 
    //each burn resistor should be on for 3 seconds 
    //turn anntenna 1 burn resistor on for 3 seconds
    //wait for 5 seconds
    //turn anntenna 2 burn resistor on for for 3 seconds 
    //wait 5 seconds , do anntenna 3 wait, anntenna 4 wait
    //if 4 feedback swithch is high
    //then depolyed is true
    //else send return with i2c to flight software
    
    //if d3 (deployA) then d11 turn high.

    if (//)
      Burn()
      if(
    }
void Deploy_B()
{
//deplays B doors
//deplay b swithches all of them sequentially
  }
void Burn(int x){
  x == HIGH;
   //once signal is recieved, send burn signal 
   //check if anntena is deployed 
}
void BurnTwice()
 {
  //if one burn resistor went off but anntenta is not deployed 
  //burn second resitor
 }
void Testing(){
  //test for burn
  //instead of burn, blink led for when the resistor should be burned 
 }
