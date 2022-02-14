clc
clear
clf

format rational
t=0:0.1:8;
%при 0<с<1/4
figure(1)
hold on
grid on
c=1/6;

for k =-10:10 %вторая константа с2
x= 1/2+(2*sqrt(1/4-c))./((k*exp(2*t*sqrt(1/4-c))-1))+sqrt(1/4-c);
plot(t,x);
title('при 0<c<1/4')
xlabel('t')
ylabel('x')
end

axis([0 7 0 5])
%при с=1/4
figure(2)
hold on
grid on
t=0:0.1:8;
c = 1/4;

for k=-10:10 %вторая константа с2
x = 0.5+1./(k+t);
plot(t,x);
title('при c = 1/4')
xlabel('t')
ylabel('x')
end

axis([0 8 0 10])
%при c > 1/4
figure(3)
grid on
hold on
syms t c k
t=0:0.1:8;
c0=2 ;

for k0=0:5 %вторая константа с2
x = subs('0.5-(sqrt(c-0.25)*tan(t+k)*sqrt(c-0.25))', c,c0);
x=subs(x,k,k0); %считаем чтобы построить
ezplot(x);
title('при c >1/4')
xlabel('t')
ylabel('x')
end

axis([0 6 0 6])