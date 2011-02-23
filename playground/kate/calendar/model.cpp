#ifndef MODEL_CPP
#define MODEL_CPP

#include "mywidget.cpp"
class Model {

private:

    int myYear;
    int myMonth;
    int **myArrayMonth;
    int *myWeeks;

public:

    Model() {
        myWeeks = new int[6];
        myArrayMonth = new int*[6];
	myYear = 2009;
	myMonth = 1;
	int i;
	int j;
        int k = 29;
	for (i =0 ; i < 6; i++) {
            myArrayMonth[i] = new int[7];
	    for (j = 0; j < 7; j++) { 
	        myArrayMonth[i][j] = k;
		k++;
		if (k == 32) {
		    k = 1;
		}
	    }
	    myWeeks[i] = (i + 1);
	}
    }
    
    int getCell(int x, int y) {
        return myArrayMonth[x][y];
    }

    int getYear() {
	return myYear;
    }

    int getMonth() {
	return myMonth;
    }

    void setYear(int year) {
	myYear = year;
    }

    void setMonth(int month) {
	myMonth = month;
    }

    int* getWeeks() {
        return myWeeks;
    }
    
    int** getArrayMonth() {
        return myArrayMonth;
    } 

    void setDownState() {
        int i;
	int j;
        int x = 0;
	int y = 0;
	for (int i = 4; i < 6; i++) {
	    for (int j = 0; j < 7; j++) {
		if (myArrayMonth[i][j] == 1) {
		    x = i;
		    y = j;
		    break;
		}
	    }
	}
        if (x == 5) {
            myWeeks[0] = myWeeks[5];
            for (i = 1; i < 6; i++) {
                myWeeks[i] = myWeeks[i - 1] + 1;
            }
        } else if (x == 4) {
           myWeeks[0] = myWeeks[4];
           for (i = 1; i < 6; i++) {
                myWeeks[i] = myWeeks[i - 1] + 1;
            }
        }
	if (y == 0) {
	    x = x - 1;
	    y = 6;
	} else {
	    y = y - 1;
	}
	int kFirst;
	int kSecond;
	kFirst = myArrayMonth[x][y];
	if (myMonth == 12) {
	    myMonth = 1;
	    myYear = myYear + 1;
             myWeeks[0] = 1;
             for (i = 1; i < 6; i++) {
                myWeeks[i] = myWeeks[i - 1] + 1;
            }
	} else {
	    myMonth = myMonth + 1;
	}
	if (myMonth == 1) {
	    kSecond = 31;
	} else if (myMonth == 2) {
	    if ((myYear % 4) == 0) {
		kSecond = 29;
	    } else {
		kSecond = 28;
	    }
	} else if (myMonth == 3) {
	    kSecond = 31;
	} else if (myMonth == 4) {
	    kSecond = 30;
	} else if (myMonth == 5) {
	    kSecond = 31;
	} else if (myMonth == 6) {
	    kSecond = 30;
	} else if (myMonth == 7) {
	    kSecond = 31;
	} else if (myMonth == 8) {
	    kSecond  = 31;
	} else if (myMonth == 9) {
	    kSecond = 30;
	} else if (myMonth == 10) {
	    kSecond = 31;
	} else if (myMonth == 11) {
	    kSecond = 30;
	} else if (myMonth == 12) {
	    kSecond = 31;
	}

        int k = myArrayMonth[x][0];
	for (i = 0; i < 6; i++) {
	    for (j = 0; j < 7; j++) {
		myArrayMonth[i][j] = k;
		if (k == kFirst) {
		    k = 1;
		    kFirst = kSecond;
		} else {
		    k++;
		}
	    }
	}
    }

    void setUpState() {
        /*int i;
	int j;
        int x = 0;
	int y = 0;
	for (int i = 0; i < 1; i++) {
	    for (int j = 0; j < 7; j++) {
		if (myArrayMonth[i][j] == 1) {
		    x = i;
		    y = j;
		    break;
		}
	    }
	}
	if (y == 0) {
	    x = x - 1;
	    y = 6;
	} else {
	    y = y - 1;
	}
	int kFirst;
	int kSecond;
	kFirst = myArrayMonth[x][y];
	if (myMonth == 1) {
	    myMonth = 12;
	    myYear = myYear - 1;
	} else {
	    myMonth = myMonth - 1;
	}
	if (myMonth == 1) {
	    kSecond = 31;
	} else if (myMonth == 2) {
	    if ((myYear % 4) == 0) {
		kSecond = 29;
	    } else {
		kSecond = 28;
	    }
	} else if (myMonth == 3) {
	    kSecond = 31;
	} else if (myMonth == 4) {
	    kSecond = 30;
	} else if (myMonth == 5) {
	    kSecond = 31;
	} else if (myMonth == 6) {
	    kSecond = 30;
	} else if (myMonth == 7) {
	    kSecond = 31;
	} else if (myMonth == 8) {
	    kSecond  = 31;
	} else if (myMonth == 9) {
	    kSecond = 30;
	} else if (myMonth == 10) {
	    kSecond = 31;
	} else if (myMonth == 11) {
	    kSecond = 30;
	} else if (myMonth == 12) {
	    kSecond = 31;
	}
        if ((kSecond + (6 - y)) > 35) {
            myArrayMonth[5] = myArrayMonth[0];
            int num = myArrayMonth[0][0];
            if (num > 2) {
                for (i = 6; i > 1; i--) {
                    for (j = 7; i > 0; j--) {
                        num = num - 1;
                        if (num != 0) { 
                            myArrayMonth[i][j] = (num);
                        }  else {
                         num = 28;

                        }

                    }
               }
           } else {
           num = 31;
           } 
        } else {
             myArrayMonth[5] = myArrayMonth[1];
             myArrayMonth[4] = myArrayMonth[0];
            (int num = myArrayMonth[4][0];
            if (num > 2) {
                for (i = 6; i > 2; i--) {
                    for (j = 7; i > 0; j--) {
                        num = num - 1;
                        if (num != 0) { 
                            myArrayMonth[i][j] = (num);
                        }  else {
                         num = 31;

                        }

                    }
                }
           } else {
               num = 31;
           }
        }*/

       

    }

};
#endif
