
/* Azip Arduino Zcode Interpreter Program
 * --------------------------------------------------------------------
 * Derived from John D. Holder's Jzip V2.1 source code
 * http://jzip.sourceforge.net/
 * --------------------------------------------------------------------
 */
 
 /*
  * Created by Louis Davis April, 2012
  *
  */

#include <SD.h>
#include "ztypes.h"

// SD chip select pin
const uint8_t chipSelect = 4;

void setup()
{
  Serial.begin(9600);
  
  Serial.println("Enter any key to start...");
  
  while (!Serial.available()) {}
  Serial.read();
 
  if (!SD.begin(chipSelect))
  {
    Serial.println("SD Card Initialisation Failure!");
    while(1);
  }

  open_story( );
  
  configure( V1, V8 );

  initialize_screen(  );

  z_restart(  );
}

void loop()
{
  interpret( );
}

