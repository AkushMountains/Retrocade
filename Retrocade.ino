int ballCoor[2] = {random(0, 8), 0};
int bucketCoor[3] = {3, 9, 0};
int score = 0;
int spdCount = 100;


void setup() {
  for(int k = 0; k < 18; k++) {
    pinMode(k, OUTPUT);
  }
  pinMode(A5, INPUT);
  resetBoard();
}


void loop() {
  drawGrid();
  delay(2);
  moveBall();
  joystick();
}


void drawGrid() {
  digitalWrite(ballCoor[1]+8, HIGH);
  digitalWrite(ballCoor[0], LOW);
  delay(2);
  digitalWrite(ballCoor[1]+8, LOW);
  digitalWrite(ballCoor[0], HIGH);
  delay(2);

  digitalWrite(bucketCoor[1]+8, HIGH);
  digitalWrite(bucketCoor[0], LOW);
  delay(2);
  digitalWrite(bucketCoor[1]+8, LOW);
  digitalWrite(bucketCoor[0], HIGH);
  delay(2);
}


void moveBall() {
  if(bucketCoor[2] > spdCount) {
    if(ballCoor[1] < 9) {
      ballCoor[1]+=1;
    } else {
      if(ballCoor[0] == bucketCoor[0]) {
        ballCoor[1] = 0;
        ballCoor[0] = random(0, 8);
        score+=1;
        if(spdCount > 15) {
          spdCount-=15;
        }
      } else {
        lose();
      }
    }
    bucketCoor[2] = 0;
  } else {
    bucketCoor[2]+=1;
  }
}


void joystick() {
  if(analogRead(A5) > 700) {
    if(bucketCoor[0] > 0) {
      bucketCoor[0]-=1;
    }
    delay(20);
  } else if(analogRead(A5) < 300) {
    if(bucketCoor[0] < 7) {
      bucketCoor[0]+=1;
    }
    delay(20);
  }
}


void lose() {
  for(int i = 0; i < 8; i++) {
    digitalWrite(i, LOW);
  }

  for(int i = 8; i < 18; i++) {
    digitalWrite(i, HIGH);
  }

  delay(2500);
  resetBoard();
}

void resetBoard() {
  for(int i = 0; i < 8; i++) {
    digitalWrite(i, HIGH);
  }

  for(int i = 8; i < 18; i++) {
    digitalWrite(i, LOW);
  }

  ballCoor[0] = random(0, 8);
  ballCoor[1] = 0;
  
  bucketCoor[0] = 3;
  bucketCoor[1] = 9;
  bucketCoor[2] = 0;
  
  score = 0;
  spdCount = 100;  
}
