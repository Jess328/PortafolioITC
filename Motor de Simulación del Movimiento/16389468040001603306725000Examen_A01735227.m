%Jesús Jiménez Aguilar
%A01735227
clc
clear all
close all
x =input('Ingrese componente en i (3):');
y =input('Ingrese componente en j (4):');
yi =input('Ingrese altura inicial (1.8):');
yf =input('Ingrese altura final (1.5):');
xi = 0;
t = (y/9.81) + (sqrt((2*((yi + (y)*((y/9.81))-((1/2)*9.81*((y/9.81))^2)) - yf))/9.81));
xf = xi + (x)*(t)
 
syms t
disp('En el eje y')
s = yi + y*t - (1/2)*(9.8*t^2)
v = diff(s)
a = diff(v)
 
disp('En el eje x')
s = x*t
v = diff(s)
a = diff(v)




