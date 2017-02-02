%Multivariate Linear Regression
%Using gradient descent
clc;
clear all;

%Loading the data----------------------------------------------------------
filename='ex1data2.txt';
data=load(filename);
X=data(:,1:2);
y=data(:,3);
[m n]=size(X);

%Training
%Feature scaling-----------------------------------------------------------

mu=mean(X); %This will return a 1Xn matrix.
sigma=std(X);%This will return a 1Xn matrix.
Xn=zeros(size(X));%normalized features

for i=1:n
  Xn(:,i)=(X(:,i)-mu(1,i))/sigma(1,i);  
end

Xn=[ones(m,1) Xn];% adding the extra column of ones before X

%Gradient descent----------------------------------------------------------
alpha=1;% the learning rate
iters=400;%number of iterations
theta=zeros(n+1,1);%parameters
J_history=zeros(iters,1);% error history


for i=1:iters
    h=Xn*theta-y;
    si=zeros(n+1,1);
    for j=1:n+1
     si(j,1)=sum(h.*Xn(:,j));
    end
    
    
   theta=theta-alpha*(1/m)*si; 
   disp(theta);
   
   
    J_history(i)=(1/(2*m))*sum((Xn*theta-y).^2);
    
end



%Plotting the error graph--------------------------------------------------
figure;
plot(1:numel(J_history), J_history, '-b', 'LineWidth', 2);
xlabel('Number of iterations');
ylabel('Cost J');
title('Error plot');


%Final theta values--------------------------------------------------------
fprintf('Theta computed from gradient descent is %f',theta);

%Testing
%Values can be predicted using the theta obtained






