import math
axis = 0
class Point:
    #have axis be a refrence`:wq
    #axis = 0
    name="defaultPoint"
    left = None
    right = None
    def __init__(self,x,y,z):
        self.mag = x**2 + y **2 + z **2
        self.coord = [self.mag,x ,y,z]
    def get_magnitude(self):
        return math.sqrt(self.mag)

    def __lt__(self,other):
        return self.coord[axis] < other.coord[axis]

    def __gt__(self,other):
        return self.coord[axis]> other.coord[axis]
    
    def __eq__(self,other):
        return self.coord[0] == other.coord[0]# && self.coord[1] == other.coord[1] &&  self.coord[2] == other.coord[2]

class PointList:
    points = [];
    degree =2;
    def sort_by_axis(self,depth):
        axis = depth % 2 +1
        self.points.sort()
    def sort_x(self):
        axis = 1
        self.points.sort()
    def sort_y(self):
        axis = 2
        self.points.sort()
    def sort_z(self):
        axis = 3
        self.points.sort()
    def toggle2d(self):
        if axis == 0:
            self.sort_y()
        else:
            self.sort_x()
    def toggle3d():
        #TODO tertiary state machine logic
        pass
    def addPoint(self,x,y,z):
        self.points.append(Point(x,y,z))
    

class KDTree:
    def __init__(self,plist,depth):
        #constricyti
        #TODO ollow constructiob steps
        axis = 0
        plist.points.sort()
        axis = 1
        self.plist()
        pivotAxis = depth % plist.length
        pass

    def constructRec(self,newplist,depth):
        
        location = int(newList.length/2)
        
        #self.newplist.toggle2d()
        
        self.plist.points[median].left = self.constructRec(newplist[0:median])
        self.plist.points[median].right = self.constructRec(newplist[median:newplist.length],depth+1)
        return self.plist.points[median]
        

