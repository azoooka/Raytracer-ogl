#include "Camera.h"



Camera::Camera(vec3 target, vec3 up, vec3 position)
{
	m_target = normalize(target);
	m_up = up;
	m_position = position;

	m_view = lookAt(m_position, m_target + m_position, m_up);
	m_projection = perspectiveFov(90, 800, 600, 0, 10000);

	m_rotateAngle = 0;

	m_frustum.ray00 = vec3(inverse(GetViewProj())*vec4(-1, -1, 1, 0));
	m_frustum.ray10 = vec3(inverse(GetViewProj())*vec4(1, -1, 1, 0));
	m_frustum.ray11 = vec3(inverse(GetViewProj())*vec4(1, 1, 1, 0));
	m_frustum.ray01 = vec3(inverse(GetViewProj())*vec4(-1, 1, 1, 0));

	m_verticalAngle = 0.f;
	m_horizonalAngle = 3.14f;
}


Camera::~Camera()
{
}

mat4 Camera::GetView()
{
	return m_view;
}
mat4 Camera::GetProj()
{
	return m_projection;
}
mat4 Camera::GetViewProj()
{
	//return m_projection * m_view;
	return rotate(m_rotateAngle, vec3(0, 1, 0));
}

void Camera::GetMouse(int x, int y)
{
	//int halfWidth = WIDTH / 2;
	//int halfHeight = HEIGHT / 2;
	//
	//if (x != halfWidth && y != halfHeight) {
	//	m_verticalAngle = (x - halfWidth);
	//	m_horizonalAngle = (y - halfHeight);
	//
	//	m_target = vec3(
	//		cos(m_verticalAngle) * sin(m_horizonalAngle),
	//		sin(m_verticalAngle),
	//		cos(m_verticalAngle) * cos(m_horizonalAngle)
	//		);
	//	glutWarpPointer(halfWidth, halfHeight);
	//}
}

void Camera::Update()
{

	m_rotateAngle = 0.1;
	
	mat4 rotation;
	rotation = rotate(m_rotateAngle, vec3(0, 1, 0));
	vec4 target4 = vec4(m_target, 0);
	target4 = target4 * rotation;
	m_target = normalize(vec3(target4.x, target4.y, target4.z));

	m_view = lookAt(m_position, m_target + m_position, m_up);

	//m_frustum.ray00 = vec3(inverse(GetViewProj())*vec4(-1, -1, 1, 0));
	//m_frustum.ray10 = vec3(inverse(GetViewProj())*vec4(1, -1, 1, 0));
	//m_frustum.ray11 = vec3(inverse(GetViewProj())*vec4(1, 1, 1, 0));
	//m_frustum.ray01 = vec3(inverse(GetViewProj())*vec4(-1, 1, 1, 0));


	//m_position.x += 0.1;


}