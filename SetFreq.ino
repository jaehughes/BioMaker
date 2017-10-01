// Due to limitations in the Arduino environment, SPI.h must be included both
//  in the library which uses it *and* any sketch using that library.
#include <SPI.h>
#include <SparkFun_MiniGen.h>


MiniGen gen(10);

void setup()
{

  gen.reset();
  delay(2000);
  // Yep.
  gen.setMode(MiniGen::SINE);
  
  gen.setFreqAdjustMode(MiniGen::FULL);

  static float frequency = 1.0;
  
  unsigned long freqReg = gen.freqCalc(10.0);
  
  // Adjust the frequency. This is a full 32-bit write.
  gen.adjustFreq(MiniGen::FREQ0, freqReg);  
  Serial.begin(9600);
}

void loop()
{

  Serial.println(analogRead(0));
}
