#include "TransformHandler.h"

D3DXMATRIX TransformHandler::GetScaleMatrix(Pair scale)
{
    D3DXMATRIX scaleMatrix;
    D3DXMatrixScaling(&scaleMatrix, scale.GetFirstValue(), scale.GetSecondValue(), 1);

    return scaleMatrix;
}

//const D3DXMATRIX* TransformHandler::GetTransformMatrix(Point cameraPoint)
//{
//    D3DXMATRIX transformMatrix;
//    D3DXMatrixIdentity(&transformMatrix);
//    transformMatrix._22 = -1;
//    transformMatrix._41 = -cameraPoint.GetFirstValue();
//    transformMatrix._42 = cameraPoint.GetSecondValue();
//
//    return &transformMatrix;
//}

D3DXVECTOR3 TransformHandler::GetPositionAfterTransform(Point positionInWorld, Point cameraPoint)
{
    /*D3DXVECTOR4 positionInViewPort;
    D3DXVec3Transform(&positionInViewPort, &positionInWorld, GetTransformMatrix(cameraPoint));

    return D3DXVECTOR3(positionInViewPort.x, positionInViewPort.y, 0);*/

    return D3DXVECTOR3(positionInWorld.GetFirstValue() - cameraPoint.GetFirstValue(), 
        -positionInWorld.GetSecondValue() + cameraPoint.GetSecondValue(), 0);
}

D3DXMATRIX TransformHandler::GetTranslationMatrix(Pair translation)
{
    D3DXMATRIX translationMatrix;
    D3DXMatrixTranslation(&translationMatrix, translation.GetFirstValue(), translation.GetSecondValue(), 
        1);

    return translationMatrix;
}

//D3DXMATRIX* TransformHandler::GetRotateMatrix(float angle)
//{
//    D3DXMATRIX rotateMatrix;
//    D3DXMatrixRotationZ(&rotateMatrix, D3DXToRadian(angle));
//
//    return &rotateMatrix;
//}