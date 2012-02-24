/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2010, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *  $id$
 *  @author: Koen Buys
 */

#ifndef PCL_PEOPLE_CONVERSION_H_
#define PCL_PEOPLE_CONVERSION_H_

#include <pcl/pcl_base.h>
#include <pcl/people/colormap.h>

namespace pcl
{
  /** 
   *  \brief This function adds a label to a PointCloudXYZRGB to output a PointCloudXYZRGBL
   *  \param[in] cloud_in the PointcloudXYZRGB
   *  \param[in] lmap vector with labels, needs to have same size as input PointCloud
   *  \param[out] cloud_out the PointCloudXYZRGBL
   **/
  void
  labelPointCloudfromArray (
                const PointCloud<PointXYZRGB>&  cloud_in,
                const uint8_t*                  lmap,
                PointCloud<PointXYZRGBL>&       cloud_out)
  {
    assert(cloud_in.isOrganized());

    int width = cloud_in.width;
    int height = cloud_in.height;

    cloud_out.width = width;
    cloud_out.height = height;

    for(unsigned int i = 0; i < cloud_in.points.size(); i++)
    {
      PointXYZRGBL p;
      p.x = cloud_in.points[i].x; p.y = cloud_in.points[i].y; p.z = cloud_in.points[i].z;
      p.r = cloud_in.points[i].r; p.g = cloud_in.points[i].g; p.b = cloud_in.points[i].b;

      p.label = lmap[i];
      cloud_out.points.push_back(p);
    }
  }
  /** 
   *  \brief This function adds a label to a PointCloudXYZ to output a PointCloudXYZL
   *  \param[in] cloud_in the PointcloudXYZ
   *  \param[in] lmap vector with labels, needs to have same size as input PointCloud
   *  \param[out] cloud_out the PointCloudXYZL
   **/
  void
  labelPointCloudfromArray (
                const PointCloud<PointXYZ>&  cloud_in,
                const uint8_t*               lmap,
                PointCloud<PointXYZL>&       cloud_out)
  {
    assert(cloud_in.isOrganized());

    int width = cloud_in.width;
    int height = cloud_in.height;

    cloud_out.width = width;
    cloud_out.height = height;

    for(unsigned int i = 0; i < cloud_in.points.size(); i++)
    {
      PointXYZL p;
      p.x = cloud_in.points[i].x; p.y = cloud_in.points[i].y; p.z = cloud_in.points[i].z;

      p.label = lmap[i];
      cloud_out.points.push_back(p);
    }
  }
  void
  colorLabelPointCloudfromArray (
                const PointCloud<PointXYZRGB>&  cloud_in,
                const uint8_t*                  lmap,
                PointCloud<PointXYZRGBL>&       cloud_out)
  {
    assert(cloud_in.isOrganized());

    int width = cloud_in.width;
    int height = cloud_in.height;

    cloud_out.width = width;
    cloud_out.height = height;

    for(unsigned int i = 0; i < cloud_in.points.size(); i++)
    {
      PointXYZRGBL p;
      p.x = cloud_in.points[i].x; p.y = cloud_in.points[i].y; p.z = cloud_in.points[i].z;
      p.label = lmap[i];
      p.b = LUT_color_label[3 * p.label + 2];
      p.g = LUT_color_label[3 * p.label + 1];
      p.r = LUT_color_label[3 * p.label + 0];
      cloud_out.points.push_back(p);
    }
  }
  void
  colorLabelPointCloudfromArray (
                const PointCloud<PointXYZ>&     cloud_in,
                const uint8_t*                  lmap,
                PointCloud<PointXYZRGBL>&       cloud_out)
  {
    assert(cloud_in.isOrganized());

    int width = cloud_in.width;
    int height = cloud_in.height;

    cloud_out.width = width;
    cloud_out.height = height;

    for(unsigned int i = 0; i < cloud_in.points.size(); i++)
    {
      PointXYZRGBL p;
      p.x = cloud_in.points[i].x; p.y = cloud_in.points[i].y; p.z = cloud_in.points[i].z;
      p.label = lmap[i];
      p.b = LUT_color_label[3 * p.label + 2];
      p.g = LUT_color_label[3 * p.label + 1];
      p.r = LUT_color_label[3 * p.label + 0];
      cloud_out.points.push_back(p);
    }
  }
}
#endif //PCL_PEOPLE_CONVERSION_H_