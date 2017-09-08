

    int suma(int num1,int num2){
        int result;
        result=num1+num2;
        return result;
    }

    int resta(int num1,int num2){
        int result;
        result=num1-num2;
        return result;
    }

    float division(float num1,float num2){
        float result;
        result=num1/num2;
        return result;
    }

    int multiplicacion(int num1,int num2){
        int result;
        result=num1*num2;
        return result;
    }

    int factorial(int num1){
        int result;
        if(num1==1)
            return 1;
            result=num1*factorial(num1-1);
        return result;
    }

