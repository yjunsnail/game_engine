#pragma once

#include <d3dx10math.h>

class CameraClass
	{
	public:
		enum CameraType{LANDOBJECT, AIRCRAFT};

	public:
		CameraClass(void);
		CameraClass(const CameraClass&);
		~CameraClass(void);

		void strafe(float units);//left & right
		void fly(float units);//up & down
		void walk(float units);

		void pitch(float angle);//turn right vector on view coordinate
		void yaw(float angle);//turn around on up direction
		void roll(float angle);//turen around on look direction

		void GetViewMatrix(D3DXMATRIX*V);
		void setCameraType(CameraType cameraType);
		void getPosition(D3DXVECTOR3* pos);
		void setPosition(D3DXVECTOR3* pos);
		//void SetRotation(float, float, float);
		void getRight(D3DXVECTOR3* right);
		void getUp(D3DXVECTOR3* up);
		void getLook(D3DXVECTOR3* look);

		//D3DXVECTOR3 GetPosition();
		//D3DXVECTOR3 GetRotation();

		//void Render();
		//void GetViewMatrix(D3DXMATRIX&);
	private:
		//float m_positionX, m_positionY, m_positionZ;//摄像机在世界坐标系中的位置
		//float m_rotationX, m_rotationY, m_rotationZ;//摄像机的欧拉旋转角度
		//D3DXMATRIX m_viewMatrix;
		CameraType _cameraType;
		D3DXVECTOR3 _right;
		D3DXVECTOR3 _up;
		D3DXVECTOR3 _look;
		D3DXVECTOR3 _pos;

	};

