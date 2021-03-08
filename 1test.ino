/// Left READ MARKER
//GND - white
//3,3 - read
//CE - orange
//scn - blue
//sck - pupple
//mosi - green
//miso -  yellow

//Подаваемая мощность. По два параметра на драйвер. Один на движение вперед, другой назад.
#define motor_RPWM_L 2
#define motor_LPWM_L 3
#define motor_RPWM_R 4
#define motor_LPWM_R 13

//Инициализация(разрешенька для движения вперед/назад)
#define motor_LL_EN 48
#define motor_LR_EN 49
#define motor_RL_EN 46
#define motor_RR_EN 47

#define motor_power 255
#define CW 1
#define STOP 0
#define CCW -1

void runMotors(int16_t leftM, int16_t rightM)
{
  if (leftM >= 0){
    analogWrite(motor_RPWM_L, 0);//назад зануляем
    analogWrite(motor_LPWM_L, abs(leftM));
  }
  else{
     analogWrite(motor_RPWM_L, abs(leftM));
     analogWrite(motor_LPWM_L, 0);
  }

  if (rightM >= 0)
  {
    analogWrite(motor_RPWM_R, 0);
    analogWrite(motor_LPWM_R, abs(rightM));
  }
  else 
  {
     analogWrite(motor_RPWM_R, abs(rightM));
     analogWrite(motor_LPWM_R, 0);
  }
}

void setup() {
  pinMode(motor_RPWM_L, OUTPUT);
  pinMode(motor_LPWM_L, OUTPUT);
  pinMode(motor_RPWM_R, OUTPUT);
  pinMode(motor_LPWM_R, OUTPUT);

  pinMode(motor_LL_EN, OUTPUT);
  pinMode(motor_LR_EN, OUTPUT);

  pinMode(motor_RL_EN, OUTPUT);
  pinMode(motor_RR_EN, OUTPUT);

  digitalWrite(motor_LL_EN, HIGH);
  digitalWrite(motor_LR_EN, HIGH);

  digitalWrite(motor_RL_EN, HIGH);
  digitalWrite(motor_RR_EN, HIGH);

}

int lValue, rValue, vLeft, vRight;
int v0 = 60;
double k = 0.05;

void loop() {
  runMotors(150, -150); 
}
