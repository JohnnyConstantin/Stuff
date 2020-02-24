package com.company;

import java.sql.SQLOutput;
import java.util.Scanner;

class Bank {
    private int n;
    private int Sum;

    void BankQuant(int n){
        this.n = n;
        System.out.println("Введите количество банкнот:");
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
    }
    void isDevidable(int a, int b, int c, int d) {
        Scanner scan = new Scanner(System.in);
        Sum = scan.nextInt();

        int k = a+b+c+d;
        int ar[] = {30, 100, 500, 1000};
        int INF=1000000000; // Значение константы
        int F[] = new int [Sum+1];
        F[0]=0;
        int m, i;
        for(m=1; m<=Sum; ++m)   // заполняем массив F
        {                     // m - сумма, которую нужно выдать
            F[m]=INF;           // помечаем, что сумму m выдать нельзя
            for(i=0; i<k; ++i)  // перебираем все номиналы банкнот
            {
                if(m>=ar[i] && F[m-ar[i]]+1<F[m])
                    F[m] = F[m-ar[i]]+1;// изменяем значение F[m], если нашли
            }                           // лучший способ выдать сумму m
        }
        if (F[Sum]==INF)
            System.out.println("Низя");
        else
            while(Sum>0)
                for(i=0;i<k;++i) {
                    if (F[Sum - ar[i]] == F[Sum] - 1) {
                        System.out.print(ar[i]);
                        System.out.print("\t");
                        Sum -= ar[i];
                        break;
                    }
                }
        /*int a1=0,b1=0,c1=0,d1=0;

            while (Sum >= 1000)
                if( a > 0){
            Sum -= 1000;
            a -= 1;
            a1+=1;
        }
            while (Sum >= 500)
                if(b>0) {
                    Sum -= 500;
                    b -= 1;
                    b1+=1;
                }
            while (Sum >= 100)
                if(c>0) {
                    Sum -= 100;
                    c -= 1;
                    c1+=1;
                }
            while (Sum >= 30)
                if(d>0) {
                    Sum -= 30;
                    d -= 1;
                    d1+=1;
                }

        if (Sum == 0){
            System.out.println("Делится");
            System.out.println(a1);
            System.out.println(b1);
            System.out.println(c1);
            System.out.println(d1);
            System.out.println(Sum);
        } else {
            System.out.println("Вашу сумму нельзя вывести банкнотами этого банкомата");
        }

    */
    }

}

public class Main {
    public static void main(String[] args) {
        int a = 1, b = 1, c = 1, d = 1;
        Bank Bank = new Bank();

        System.out.println("Номинал: 1000");
        Bank.BankQuant(a);
        System.out.println("Номинал: 500");
        Bank.BankQuant(b);
        System.out.println("Номинал: 100");
        Bank.BankQuant(c);
        System.out.println("Номинал: 30");
        Bank.BankQuant(d);
        System.out.println("Введите сумму для снятия");
        Bank.isDevidable(a,b,c,d);

    }
}
