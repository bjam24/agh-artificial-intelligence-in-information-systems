/*
   Copyright 2021 FogML

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

int classifier(float * x){
  int results[5];
  if (x[0] <= 5.4500000477) {
    if (x[3] <= 0.8000000119) {
      results[0] = 0;
    }
    else {
      if (x[3] <= 1.6000000238) {
        results[0] = 1;
      }
      else {
        results[0] = 2;
      }
    }
  }
  else {
    if (x[2] <= 4.8500001431) {
      if (x[2] <= 2.6000000238) {
        results[0] = 0;
      }
      else {
        results[0] = 1;
      }
    }
    else {
      if (x[3] <= 1.6999999881) {
        if (x[3] <= 1.5500000119) {
          results[0] = 2;
        }
        else {
          results[0] = 1;
        }
      }
      else {
        results[0] = 2;
      }
    }
  }
  if (x[2] <= 2.4499999881) {
    results[1] = 0;
  }
  else {
    if (x[3] <= 1.6500000358) {
      if (x[2] <= 4.9500000477) {
        results[1] = 1;
      }
      else {
        results[1] = 2;
      }
    }
    else {
      results[1] = 2;
    }
  }
  if (x[0] <= 5.4500000477) {
    if (x[2] <= 2.3500000238) {
      results[2] = 0;
    }
    else {
      results[2] = 1;
    }
  }
  else {
    if (x[2] <= 4.7500000000) {
      if (x[3] <= 0.6000000015) {
        results[2] = 0;
      }
      else {
        results[2] = 1;
      }
    }
    else {
      if (x[3] <= 1.7500000000) {
        if (x[3] <= 1.5500000119) {
          if (x[2] <= 5.0000000000) {
            results[2] = 1;
          }
          else {
            results[2] = 2;
          }
        }
        else {
          results[2] = 1;
        }
      }
      else {
        if (x[0] <= 5.9500000477) {
          if (x[1] <= 3.1000000238) {
            results[2] = 2;
          }
          else {
            results[2] = 1;
          }
        }
        else {
          results[2] = 2;
        }
      }
    }
  }
  if (x[3] <= 0.8000000119) {
    results[3] = 0;
  }
  else {
    if (x[2] <= 4.8500001431) {
      if (x[3] <= 1.6999999881) {
        results[3] = 1;
      }
      else {
        if (x[1] <= 3.1000000238) {
          results[3] = 2;
        }
        else {
          results[3] = 1;
        }
      }
    }
    else {
      if (x[3] <= 1.7500000000) {
        if (x[2] <= 4.9500000477) {
          results[3] = 1;
        }
        else {
          if (x[3] <= 1.6500000358) {
            results[3] = 2;
          }
          else {
            results[3] = 1;
          }
        }
      }
      else {
        results[3] = 2;
      }
    }
  }
  if (x[2] <= 2.4499999881) {
    results[4] = 0;
  }
  else {
    if (x[3] <= 1.6000000238) {
      if (x[1] <= 2.6499999762) {
        if (x[3] <= 1.3000000119) {
          results[4] = 1;
        }
        else {
          if (x[3] <= 1.4499999881) {
            results[4] = 2;
          }
          else {
            results[4] = 1;
          }
        }
      }
      else {
        results[4] = 1;
      }
    }
    else {
      if (x[2] <= 4.8500001431) {
        if (x[2] <= 4.6500000954) {
          results[4] = 2;
        }
        else {
          if (x[1] <= 3.1000000238) {
            results[4] = 2;
          }
          else {
            results[4] = 1;
          }
        }
      }
      else {
        results[4] = 2;
      }
    }
  }
  int classes_amount = 0;
  for(int i=0; i<5; i++){
  	if(results[i]+1 > classes_amount) classes_amount = results[i]+1;  }
  int result_class = -1;
  int max_apperance = 0;
  for(int i=0; i<classes_amount; i++){
   int apperance = 0;
  	for(int j=0; j<5; j++) if(results[j] == i) apperance++;
  	if(apperance > max_apperance){
  		max_apperance = apperance;
  		result_class = i;
  	}
  }
  return result_class;
}
