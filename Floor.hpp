/*
 * Copyright (c) 2012, Joseph Max DeLiso, Daniel Gilbert
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of the FreeBSD Project.
 */

#ifndef _FLOOR_H
#define _FLOOR_H

#include "ElevatorSim.hpp"
#include "Location.hpp"
#include "Person.hpp"
#include "ISimulationTerminal.hpp"
#include "Building.hpp"

#include <vector>

namespace elevatorSim {

class Building;
class Person;

class Floor : public Location, public ISimulationTerminal {

   /* friends */
   friend class Building;

   /* private static constants */

   /* private static methods */

   /* private instance members */
   std::vector<Person> occupants;
   bool signalingUp;
   bool signalingDown;
   const int thisFloor;
   const GLfloat gfxScaleWidth;
   const bool hasUpperFloor;
   const bool hasLowerFloor;

   /* private methods */

   /* constructors */
   Floor(
      int _yVal,
      int _thisFloor,
      float _gfxScaleWidth,
      bool _hasUpperFloor = false,
      bool _hasLowerFloor = false  );

public:

   /* public static constants */
   static const int YVALS_PER_FLOOR;

   /* public instance members */

   ~Floor();

   /* public methods inherited from ISimulationTerminal*/
   void init();
   void render();
   void update();

   void addOccupant(int numOfPeople, int destination);
   int getNumOccupants()   {  return occupants.size();   }
};

} /* namespace elevatorSim */

#endif /* _FLOOR_H */
