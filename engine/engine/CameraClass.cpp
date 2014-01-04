#include "CameraClass.h"


CameraClass::CameraClass(void)
{
	_cameraType = AIRCRAFT;

	_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	_right = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	_up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	_look = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
}

CameraClass::CameraClass(const CameraClass& other)
{
}

CameraClass::~CameraClass(void)
{
}

void CameraClass::getPosition(D3DXVECTOR3* pos)
{
	*pos = _pos;
}

void CameraClass::setPosition(D3DXVECTOR3* pos)
{
	_pos = *pos;
}

void CameraClass::getRight(D3DXVECTOR3* right)
{
	*right = _right;
}

void CameraClass::getUp(D3DXVECTOR3* up)
{
	*up = _up;
}

void CameraClass::getLook(D3DXVECTOR3* look)
{
	*look = _look;
}

//Walking in camera direction
void CameraClass::walk(float units)
{
	//only on X Z plane
	if (_cameraType == LANDOBJECT)
	{
		_pos += D3DXVECTOR3(_look.x, 0.0, _look.z) * units;
	}
	if (_cameraType == AIRCRAFT)
	{
		_pos += _look * units;
	}

}

//Keeping looking direction and moving on right direction
void CameraClass::strafe(float units)
{
	//only on X Z plane
	if (_cameraType == LANDOBJECT)
	{
		_pos += D3DXVECTOR3(_right.x, 0.0f, _right.z) * units;
	}
	if (_cameraType == AIRCRAFT)
	{
		_pos += _right * units;
	}
}

//moving on up direction
void CameraClass::fly(float units)
{
	//only moving on Y direction
	if (_cameraType == LANDOBJECT)
	{
		_pos.y += units;
	}
	if (_cameraType == AIRCRAFT)
	{
		_pos += _up * units;
	}
}

void CameraClass::pitch(float angle)
{
	D3DXMATRIX T;
	D3DXMatrixRotationAxis(&T, &_right, angle);

	//turn around the up and look on right vector
	D3DXVec3TransformCoord(&_up, &_up, &T);
	D3DXVec3TransformCoord(&_look, &_look, &T);

}

void CameraClass::yaw(float angle)
{
	D3DXMATRIX T;

	//turn around on (0, 1, 0) in LANDOBJECT


}
