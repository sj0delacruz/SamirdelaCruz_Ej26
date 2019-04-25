import numpy as np
import matplotlib.pyplot as plt

def grafica(x,y,t,xl,yl,c,lim):
    plt.title(t)
    plt.plot(x,y,c=c)
    plt.xlabel(xl)
    plt.ylabel(yl)
    plt.xlim(lim[0][0],lim[0][1])
    plt.ylim(lim[1][0],lim[1][1])

dat_euler = np.loadtxt("euler_0o5_ec1.dat")
dat_rompeku = np.loadtxt("rompeku_0o5_ec1.dat")
dat_rana = np.loadtxt("rana_0o5_ec1.dat")

plt.figure(figsize=(15,15))
plt.subplot(3,3,1)
grafica(dat_euler[:,0],dat_euler[:,1],"Euler","$x$","$y$",'r',[[0,12.5],[-1.5,1.5]])
plt.subplot(3,3,4)
grafica(dat_euler[:,0],dat_euler[:,2],"","$x$","$y'$",'r',[[0,12.5],[-1.5,1.5]])
plt.subplot(3,3,7)
grafica(dat_euler[:,1],dat_euler[:,2],"","$y$","$y'$",'r',[[-2,2],[-2,2]])

plt.subplot(3,3,2)
grafica(dat_rompeku[:,0],dat_rompeku[:,1],"Runge Kutta","$x$","$y$",'b',[[0,12.5],[-1.5,1.5]])
plt.subplot(3,3,5)
grafica(dat_rompeku[:,0],dat_rompeku[:,2],"","$x$","$y'$",'b',[[0,12.5],[-1.5,1.5]])
plt.subplot(3,3,8)
grafica(dat_rompeku[:,1],dat_rompeku[:,2],"","$y$","$y'$",'b',[[-2,2],[-2,2]])

plt.subplot(3,3,3)
grafica(dat_rana[:,0],dat_rana[:,1],"Leapfrog","$x$","$y$",'g',[[0,12.5],[-1.5,1.5]])
plt.subplot(3,3,6)
grafica(dat_rana[:,0],dat_rana[:,2],"","$x$","$y'$",'g',[[0,12.5],[-1.5,1.5]])
plt.subplot(3,3,9)
grafica(dat_rana[:,1],dat_rana[:,2],"","$y$","$y'$",'g',[[-2,2],[-2,2]])

plt.savefig("graf_sol_0o5_ec1.png")

