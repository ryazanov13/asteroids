/* File collision.cpp */
#include "collision.h"

int Collision::ClassifyPoint(Point p1, Point p2, Point p){
  float ax,ay,bx,by;
  ax = p2.x - p1.x;
  ay = p2.y - p1.y;
  bx = p.x - p1.x;
  by = p.y - p1.y;
  float sa = ax * by - bx * ay;
  if (sa > 0.0)
    return 0;//LEFT
  if (sa < 0.0)
    return 1;//RIGHT
  if ((ax * bx < 0.0) || (ay * by < 0.0))
    return 2;//BEHIND
  if (sqrt(ax*ax + ay*ay) < sqrt(bx*bx + by*by))
    return 3;//BEYOND
  if (p1.x == p.x && p1.y == p.y)
    return 4;//ORIGIN
  if (p2.x == p.x && p2.y == p.y)
    return 5;//DESTINATION
  return 6;//BETWEEN
}
bool Collision::IsIntersection(Point a1, Point a2, Point b1, Point b2){
  float v1=(b2.x-b1.x)*(a1.y-b1.y)-(b2.y-b1.y)*(a1.x-b1.x);
  float v2=(b2.x-b1.x)*(a2.y-b1.y)-(b2.y-b1.y)*(a2.x-b1.x);
  float v3=(a2.x-a1.x)*(b1.y-a1.y)-(a2.y-a1.y)*(b1.x-a1.x);
  float v4=(a2.x-a1.x)*(b2.y-a1.y)-(a2.y-a1.y)*(b2.x-a1.x);
  return (v1*v2<0) && (v3*v4<0);
}
std::vector<Point> Collision::CreateTrail(Object object){
  float a1, b1;
  Point p1, p2;
  // p1 = object.GetCurrentPosition();
  // p2 = object.GetPrevPosition();
  p1 = object.GetPolygon().GetPosition();
  p2 = object.GetPrevPosition()-(object.GetCurrentPosition()-p1);

  float length = 0.0, max_left_length = 0.0, max_right_length = 0.0;
  int left_index, right_index;
  std::vector<Point> points = object.GetPolygon().GetPoints();

  if((p2.x - p1.x)==0 && (p2.y - p1.y)!=0){;
    for(int i = 0;i<points.size();++i){
      if(ClassifyPoint(p1,p2,points[i])==0){;
        length = std::abs(points[i].x-p1.x);
        if(max_left_length < length){
          max_left_length = length;
          left_index=i;
        }
      }
      else if(ClassifyPoint(p1,p2,points[i])==1){
        length = std::abs(points[i].x-p1.x);
        if(max_right_length < length){;
          max_right_length = length;
          right_index=i;
        }
      }
    }
  }
  else if((p2.y - p1.y)==0 && (p2.x - p1.x)!=0){
    for(int i = 0;i<points.size();++i){
      if(ClassifyPoint(p1,p2,points[i])==0){
        length = std::abs(points[i].y-p1.y);
        if(max_left_length < length){
          max_left_length = length;
          left_index=i;
        }
      }
      else if(ClassifyPoint(p1,p2,points[i])==1){
        length = std::abs(points[i].y-p1.y);
        if(max_right_length < length){
          max_right_length = length;
          right_index=i;
        }
      }
    }
  }
  else if((p2.y - p1.y)!=0 && (p2.x - p1.x)!=0){
    float a2, b2, c_x, c_y;
    a1 = -(p2.x - p1.x)/(p2.y - p1.y);
    b1 = (p1.x*(p2.x - p1.x))/(p2.y - p1.y) + p1.y;
    for(int i = 0;i<points.size();++i){
      a2 = -1/a1;
      b2 = points[i].x/a1 + points[i].y;
      c_x = (b1-b2)/(a2-a1);
      c_y = a2*c_x + b2;
      if(ClassifyPoint(p1,p2,points[i])==0){
        length = get_segment_length(p1,Point(c_x,c_y));
        if(max_left_length < length){
          max_left_length = length;
          left_index=i;
        }
      }
      else if(ClassifyPoint(p1,p2,points[i])==1){
        length = get_segment_length(p1,Point(c_x,c_y));
        if(max_right_length < length){
          max_right_length = length;
          right_index=i;
        }
      }
    }
  }
  else{
    return points;
  }

  std::vector<Point> new_points(points.size()+2);
  int i = left_index;
  int j = 0;
  while(true){
    if(i==points.size()){
      i=0;
    }
    new_points[j]=points[i];
    ++j;
    if(i==right_index){
      break;
    }
    ++i;
  }
  while(true){
    if(i==points.size()){
      i=0;
    }
    new_points[j]=points[i]-(p1-p2);
    ++j;
    if(i==left_index){
      break;
    }
    ++i;
  }
  return new_points;
}
bool Collision::CheckInside(int i){
  switch(i){
    case 0:
      return true;
    case 1:
      return false;
    case 2:
      return false;
    case 3:
      return false;
    case 4:
      return true;
    case 5:
      return true;
    case 6:
      return true;
  }
}
bool Collision::CheckLines(std::vector<Point> p1, std::vector<Point> p2){
  int i,j;
  i=0;
  while(i<p1.size()-1){
    j=0;
    while(j<p2.size()-1){
      if(IsIntersection(p1[i],p1[i+1],p2[j],p2[j+1])){
        return true;
      }
      ++j;
    }
    if(IsIntersection(p1[i],p1[i+1],p2[j],p2[0])){
      return true;
    }
    ++i;
  }
  j=0;
  while(j<p2.size()-1){
    if(IsIntersection(p1[i],p1[0],p2[j],p2[j+1])){
      return true;
    }
    ++j;
  }
  if(IsIntersection(p1[i],p1[0],p2[j],p2[0])){
    return true;
  }
  return false;
}
bool Collision::CheckPoints(std::vector<Point> p1, std::vector<Point> p2){
  int j;
  bool res;
  for(int i=0;i<p1.size();++i){
    j=0;
    res = true;
    while(j<p2.size()-1){
      res=res&&CheckInside(ClassifyPoint(p2[j],p2[j+1],p1[i]));
      ++j;
    }
    res=res&&CheckInside(ClassifyPoint(p2[j],p2[0],p1[i]));
    if(res){
      return true;
    }
    ++i;
  }
  return false;
}
std::vector<Point> Collision::CreateCollisionArea(Object object){
  std::vector<Point> points(4);
  if(object.GetCurrentPosition().x>object.GetPrevPosition().x){
    points[0].x = object.GetPrevPosition().x - object.GetW()/2;
    points[1].x = object.GetCurrentPosition().x + object.GetW()/2;
    points[2].x = object.GetCurrentPosition().x + object.GetW()/2;
    points[3].x = object.GetPrevPosition().x - object.GetW()/2;
  }
  else{
    points[0].x = object.GetCurrentPosition().x - object.GetW()/2;
    points[1].x = object.GetPrevPosition().x + object.GetW()/2;
    points[2].x = object.GetPrevPosition().x + object.GetW()/2;
    points[3].x = object.GetCurrentPosition().x - object.GetW()/2;
  }
  if(object.GetCurrentPosition().y>object.GetPrevPosition().y){
    points[0].y = object.GetPrevPosition().y - object.GetH()/2;
    points[1].y = object.GetPrevPosition().y - object.GetH()/2;
    points[2].y = object.GetCurrentPosition().y + object.GetH()/2;
    points[3].y = object.GetCurrentPosition().y + object.GetH()/2;
  }
  else{
    points[0].y = object.GetCurrentPosition().y - object.GetH()/2;
    points[1].y = object.GetCurrentPosition().y - object.GetH()/2;
    points[2].y = object.GetPrevPosition().y + object.GetH()/2;
    points[3].y = object.GetPrevPosition().y + object.GetH()/2;
  }
  return points;
}
bool Collision::PreCheck(Object obj1, Object obj2){
  std::vector<Point> p1, p2;
  p1=CreateCollisionArea(obj1);
  p2=CreateCollisionArea(obj2);
  return CheckLines(p1,p2)||CheckPoints(p1,p2)||CheckPoints(p2,p1);
}
bool Collision::FullCheck(Object obj1, Object obj2){
  std::vector<Point> p1, p2;
  p1=CreateTrail(obj1);
  p2=CreateTrail(obj2);
  return CheckLines(p1,p2)||CheckPoints(p1,p2)||CheckPoints(p2,p1);
}
bool Collision::CheckObjects(Object obj1, Object obj2){
  if(PreCheck(obj1,obj2)){
    return FullCheck(obj1,obj2);
  }
  return false;
}
