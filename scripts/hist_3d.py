import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.colors as colors
import matplotlib.cm as cmx

plt.rcParams["font.family"] = "Times New Roman"

# my data
fname = "result/1D.txt"
dat = np.loadtxt(fname)
dat = np.reshape(dat,[64,64],order='C')

lx = len(dat[0])
ly = len(dat[:,0])
n = lx*ly

# generate plot data
xpos = np.arange(0,lx,1)  
ypos = np.arange(0,ly,1)
xpos, ypos = np.meshgrid(xpos+0.25, ypos+0.25)
xpos = xpos.flatten()
ypos = ypos.flatten()
zpos = np.zeros(n)
dx = 0.5*np.ones_like(zpos)
dy = dx.copy()
dz = dat.flatten()
cc = np.tile(range(lx), (ly,1))
cc = cc.T.flatten()

# generate plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

color = "cool"
#color = "plasma"
#color = "winter"

# data's color
norm = plt.Normalize(0,dz.max())
cmap = plt.get_cmap(color)

# color bar
scalarMap = cmx.ScalarMappable(norm=norm, cmap=color)
cbar = fig.colorbar(scalarMap, pad=0.18, shrink = 0.55)
cbar.set_label("Probability")

bar = ax.bar3d(xpos, ypos, zpos, dx, dy, dz, color=cmap(norm(dz)))

ax.set_title("Co-occurrence probability", fontsize=16)
ax.set_xlabel("p")
ax.set_ylabel("q")
ax.set_zlabel("Probability")

plt.autoscale(enable=True, axis='both', tight=True)
plt.grid()
fname = "result/3D.png"
plt.savefig(fname)
#plt.show()
