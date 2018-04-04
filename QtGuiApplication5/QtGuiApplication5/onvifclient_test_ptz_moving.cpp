// onvifclient.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "onvifclient.hpp"

/*

int main(int argc, _TCHAR* argv[])
{

	DeviceBindingProxy proxyDevice;
	
	PTZBindingProxy proxyPTZ;
	std::string urlPTZ = "http://192.168.1.1:8080/onvif/ptz_service";
	proxyPTZ.soap_endpoint = urlPTZ.c_str();
	//soap_register_plugin(proxyPTZ.soap, soap_wsse);
	struct soap *soap;
	soap = soap_new();
	_tptz__GetConfigurations *tptz__GetConfigurations = soap_new__tptz__GetConfigurations(soap, -1);
	_tptz__GetConfigurationsResponse *tptz__GetConfigurationsResponse = soap_new__tptz__GetConfigurationsResponse(soap, -1);

	if (SOAP_OK == proxyPTZ.GetConfigurations(tptz__GetConfigurations, tptz__GetConfigurationsResponse)) {
		for (int i = 0; i<tptz__GetConfigurationsResponse->PTZConfiguration.size(); ++i) {
			std::cout << "ConfigurationToken #" << i << ": " << tptz__GetConfigurationsResponse->PTZConfiguration[i]->token << std::endl;
		}
	}

	soap_destroy(soap);
	soap_end(soap);
	// -------------------------------------------------
	MediaBindingProxy proxyMedia;
	std::string urlMedia = "http://192.168.1.1:8080/onvif/media_service";
	proxyMedia.soap_endpoint = urlMedia.c_str();

	//struct soap *soap2;
	//soap2 = soap_new();

	_trt__GetVideoSourceConfigurations *trt__GetVideoSourceConfigurations = soap_new__trt__GetVideoSourceConfigurations(soap, -1);
	_trt__GetVideoSourceConfigurationsResponse *trt__GetVideoSourceConfigurationsResponse = soap_new__trt__GetVideoSourceConfigurationsResponse(soap, -1);

	if (SOAP_OK == proxyMedia.GetVideoSourceConfigurations(trt__GetVideoSourceConfigurations, trt__GetVideoSourceConfigurationsResponse)) {
		for (int i = 0; i<trt__GetVideoSourceConfigurationsResponse->Configurations.size(); ++i) {
			std::cout << "Name:" << trt__GetVideoSourceConfigurationsResponse->Configurations[i]->Name << std::endl << "UseCount" << trt__GetVideoSourceConfigurationsResponse->Configurations[i]->UseCount << std::endl << "Token:" << trt__GetVideoSourceConfigurationsResponse->Configurations[i]->token << std::endl << "SourceToken:" << trt__GetVideoSourceConfigurationsResponse->Configurations[i]->SourceToken << std::endl << "X_bound: " << trt__GetVideoSourceConfigurationsResponse->Configurations[i]->Bounds->x << std::endl << "Y_bound: " << trt__GetVideoSourceConfigurationsResponse->Configurations[i]->Bounds->y << std::endl << "Width_bound::" << trt__GetVideoSourceConfigurationsResponse->Configurations[i]->Bounds->width << std::endl << "Height_bound" << trt__GetVideoSourceConfigurationsResponse->Configurations[i]->Bounds->height << std::endl;
			std::cout << std::endl;

		}
	}
	soap_destroy(soap);
	soap_end(soap);

	_trt__GetVideoEncoderConfigurations *trt__GetVideoEncoderConfigurations = soap_new__trt__GetVideoEncoderConfigurations(soap, -1);
	_trt__GetVideoEncoderConfigurationsResponse *trt__GetVideoEncoderConfigurationsResponse = soap_new__trt__GetVideoEncoderConfigurationsResponse(soap, -1);

	if (SOAP_OK == proxyMedia.GetVideoEncoderConfigurations(trt__GetVideoEncoderConfigurations, trt__GetVideoEncoderConfigurationsResponse)) {
		for (int i = 0; i<trt__GetVideoEncoderConfigurationsResponse->Configurations.size(); ++i) {
			std::cout << "VideoEncoderToken #" << i << ": " << trt__GetVideoEncoderConfigurationsResponse->Configurations[i]->token << std::endl;
			std::cout << "Name:" << trt__GetVideoEncoderConfigurationsResponse->Configurations[i]->Name << std::endl << "UseCount: " << trt__GetVideoEncoderConfigurationsResponse->Configurations[i]->UseCount << std::endl << "Encoding:" << trt__GetVideoEncoderConfigurationsResponse->Configurations[i]->Encoding << std::endl << "Resolution:" << trt__GetVideoEncoderConfigurationsResponse->Configurations[i]->Resolution->Width << "x" << trt__GetVideoEncoderConfigurationsResponse->Configurations[i]->Resolution->Height << std::endl << "Quality:" << trt__GetVideoEncoderConfigurationsResponse->Configurations[i]->Quality << std::endl << "FrameRateLimit:" << trt__GetVideoEncoderConfigurationsResponse->Configurations[i]->RateControl->FrameRateLimit << std::endl << "EncodingInterval:" << trt__GetVideoEncoderConfigurationsResponse->Configurations[i]->RateControl->EncodingInterval << std::endl << "BitrateLimit:" << trt__GetVideoEncoderConfigurationsResponse->Configurations[i]->RateControl->BitrateLimit << std::endl;
			std::cout << std::endl;
		}

	}
	else {
		//PrintErr(proxyMedia.soap);
	}

	soap_destroy(soap);
	soap_end(soap);

	_trt__CreateProfile *trt__CreateProfile = soap_new__trt__CreateProfile(soap, -1);
	_trt__CreateProfileResponse *trt__CreateProfileResponse = soap_new__trt__CreateProfileResponse(soap, -1);

	trt__CreateProfile->Name = "PTZ";
	std::string profileToken = "PTZ";
	trt__CreateProfile->Token = &profileToken;

	if (SOAP_OK == proxyMedia.CreateProfile(trt__CreateProfile, trt__CreateProfileResponse)) {
		std::cout << "profile created" << std::endl;
	}
	
	soap_destroy(soap);
	soap_end(soap);

	_trt__AddPTZConfiguration *trt__AddPTZConfiguration = soap_new__trt__AddPTZConfiguration(soap, -1);
	_trt__AddPTZConfigurationResponse *trt__AddPTZConfigurationResponse = soap_new__trt__AddPTZConfigurationResponse(soap, -1);

	trt__AddPTZConfiguration->ProfileToken = profileToken;
	trt__AddPTZConfiguration->ConfigurationToken = "PTZConfigurationToken"; 

	if (SOAP_OK == proxyMedia.AddPTZConfiguration(trt__AddPTZConfiguration, trt__AddPTZConfigurationResponse)) {
		std::cout << "check configuration added" << std::endl;
	}
	else {
		//PrintErr(proxyMedia.soap);
	}

	soap_destroy(soap);
	soap_end(soap);

	// ---------- move -----
	_tptz__GotoHomePosition* tptz__GotoHomePosition = soap_new__tptz__GotoHomePosition(soap);
	_tptz__GotoHomePositionResponse* tptz__GotoHomePositionResponse = new _tptz__GotoHomePositionResponse();
	int x = proxyPTZ.GotoHomePosition(urlPTZ.c_str(), NULL, tptz__GotoHomePosition, tptz__GotoHomePositionResponse);


	_tptz__AbsoluteMove *tptz__AbsoluteMove = soap_new__tptz__AbsoluteMove(soap, -1);
	_tptz__AbsoluteMoveResponse *tptz__AbsoluteMoveResponse = soap_new__tptz__AbsoluteMoveResponse(soap, -1);

	tptz__AbsoluteMove->ProfileToken = "PTZConfigurationToken";

	//setting pan and tilt
	tptz__AbsoluteMove->Position = soap_new_tt__PTZVector(soap, -1);
	tptz__AbsoluteMove->Position->PanTilt = soap_new_tt__Vector2D(soap, -1);
	tptz__AbsoluteMove->Speed = soap_new_tt__PTZSpeed(soap, -1);
	tptz__AbsoluteMove->Speed->PanTilt = soap_new_tt__Vector2D(soap, -1);
	//pan
	tptz__AbsoluteMove->Position->PanTilt->x = 200;
	tptz__AbsoluteMove->Speed->PanTilt->x = 0.01;
	//tilt
	tptz__AbsoluteMove->Position->PanTilt->y = 200;
	tptz__AbsoluteMove->Speed->PanTilt->y = 0.5;
	//setting zoom
	tptz__AbsoluteMove->Position->Zoom = soap_new_tt__Vector1D(soap, -1);
	tptz__AbsoluteMove->Speed->Zoom = soap_new_tt__Vector1D(soap, -1);
	tptz__AbsoluteMove->Position->Zoom->x = 1;
	tptz__AbsoluteMove->Speed->Zoom->x = 0.5;

	if (SOAP_OK == proxyPTZ.AbsoluteMove(tptz__AbsoluteMove, tptz__AbsoluteMoveResponse)) {
		std::cout << "check move done" << std::endl;
	}
	else {
		std::cout << "AbsoluteMove ERROR:" << std::endl;
		//PrintErr(proxyPTZ.soap);
		std::cout << std::endl;
	}

	soap_destroy(soap);
	soap_end(soap);

	return 0;
}
*/
//---------------------------------------------------------------


/*
#include "stdafx.h"
#include "onvifclient.hpp"


int main(int argc, _TCHAR* argv[])
{
	
	struct soap soap;

	soap_init(&soap);

	DeviceBindingProxy proxy(soap);

	_tds__GetDeviceInformation tds__GetDeviceInformation;
	_tds__GetDeviceInformationResponse tds__GetDeviceInformationResponse;

	std::string endpoint = "http://192.168.1.1:8080/onvif/device_service";

	int result = SOAP_ERR;

	result = proxy.GetDeviceInformation(endpoint.c_str(), NULL,
		&tds__GetDeviceInformation, &tds__GetDeviceInformationResponse);

	if (result == SOAP_OK)
	{
		std::cout << "Mfr: " << tds__GetDeviceInformationResponse.Manufacturer << std::endl;
		std::cout << "Model: " << tds__GetDeviceInformationResponse.Model << std::endl;
		std::cout << "F/W version: " << tds__GetDeviceInformationResponse.FirmwareVersion << std::endl;
	}

	
	return 0;
}
//---------------------------------------------------------------
*/	



int main(int argc, _TCHAR* argv[])
{
	
	PTZBindingProxy proxyPTZ;
	std::string urlPTZ = "http://192.168.1.1:8080/onvif/ptz_service"; 
	proxyPTZ.soap_endpoint = urlPTZ.c_str();
	struct soap *soap_;
	soap_ = soap_new();
	_tptz__GetConfigurations *tptz__GetConfigurations = soap_new__tptz__GetConfigurations(soap_, -1);
	_tptz__GetConfigurationsResponse *tptz__GetConfigurationsResponse = soap_new__tptz__GetConfigurationsResponse(soap_, -1);
	
	//
	MediaBindingProxy proxyMedia;
	std::string urlMedia = "http://192.168.1.1:8080/onvif/media_service";
	proxyMedia.soap_endpoint = urlMedia.c_str();

	_trt__GetProfiles trt__GetProfiles;
	_trt__GetProfilesResponse trt__GetProfilesResponse;
	proxyMedia.GetProfiles(&trt__GetProfiles, &trt__GetProfilesResponse);
	//trt__GetProfilesResponse.Profiles[0]->token;
		
	//
	_tptz__AbsoluteMove *AbsoluteMoveReq = soap_new__tptz__AbsoluteMove(&proxyPTZ, -1);
	AbsoluteMoveReq->ProfileToken = trt__GetProfilesResponse.Profiles[0]->token;
												   
	AbsoluteMoveReq->Position = soap_new_tt__PTZVector(&proxyPTZ, -1);
	AbsoluteMoveReq->Position->PanTilt = soap_new_tt__Vector2D(&proxyPTZ, -1);
	AbsoluteMoveReq->Speed = soap_new_tt__PTZSpeed(&proxyPTZ, -1);
	AbsoluteMoveReq->Speed->PanTilt = soap_new_tt__Vector2D(&proxyPTZ, -1);
	//pan
	AbsoluteMoveReq->Position->PanTilt->x = -0.9798;
	AbsoluteMoveReq->Position->PanTilt->y = 0.6768;

	//tilt
	AbsoluteMoveReq->Speed->PanTilt->x = 10000.0;
	AbsoluteMoveReq->Speed->PanTilt->y = 10000.0;

	//setting zoom
	AbsoluteMoveReq->Position->Zoom = soap_new_tt__Vector1D(&proxyPTZ, -1);
	AbsoluteMoveReq->Speed->Zoom = soap_new_tt__Vector1D(&proxyPTZ, -1);
	AbsoluteMoveReq->Position->Zoom->x = 0.7646;
	AbsoluteMoveReq->Speed->Zoom->x = 5.0;

	_tptz__AbsoluteMoveResponse AbsoluteMoveResponse;
	int x = proxyPTZ.AbsoluteMove(AbsoluteMoveReq, &AbsoluteMoveResponse);

	//
	_tptz__ContinuousMove* tptz__ContinuousMove = soap_new__tptz__ContinuousMove(&proxyPTZ, -1);
	tptz__ContinuousMove->ProfileToken = trt__GetProfilesResponse.Profiles[0]->token;
	
	tt__PTZSpeed* velocity = soap_new_tt__PTZSpeed(&proxyPTZ, -1);
	tptz__ContinuousMove->Velocity = velocity;
	tt__Vector2D* panTilt = soap_new_tt__Vector2D(&proxyPTZ, -1);
	tptz__ContinuousMove->Velocity->PanTilt = panTilt;
	//tptz__ContinuousMove->Velocity->PanTilt->space = "http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace";
	tt__Vector1D* zoom = soap_new_tt__Vector1D(&proxyPTZ, -1);
	tptz__ContinuousMove->Velocity->Zoom = zoom;
	tptz__ContinuousMove->Velocity->PanTilt->x = -((float)0.5 / 10);
	tptz__ContinuousMove->Velocity->PanTilt->y = 0;

	_tptz__ContinuousMoveResponse tptz__ContinuousMoveResponse;
	int y = proxyPTZ.ContinuousMove(tptz__ContinuousMove, &tptz__ContinuousMoveResponse);
	
	
	/*
	int ret;
	// 192.168.1.1 is the NVT, 192.168.1.234 is the NVC
	string url = "http://192.168.1.1:8080/onvif/device_service";
	// Below is where to receive the event 
	string eventNotify = "http://192.168.1.1:8080/onvif/event_service";
	string user = "";
	string pass =  "";
	OnvifClientDevice onvifDevice(url, user, pass);
	_tds__GetCapabilitiesResponse capabilitiesResponse;

	onvifDevice.GetCapabilities();

	OnvifClientMedia media(onvifDevice);
	_trt__GetProfilesResponse profiles;
	media.GetProfiles(profiles);
	
	int size = profiles.Profiles.size();
	std::cout << "profilesResponse.Profiles[i]->token" << endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << profiles.Profiles[i]->token << endl;
	}

	OnvifClientPTZ ptzClient(onvifDevice);

	_tptz__GetStatusResponse StatusResponse;
	ptzClient.GetStatus(StatusResponse, "PTZ");

	_tptz__AbsoluteMoveResponse AbsoluteMoveResponse;
	tt__PTZSpeed Speed;
	tt__PTZVector position;
	ptzClient.AbsoluteMove(AbsoluteMoveResponse, Speed, position, "PTZ");

	// Recording ----
	OnvifClientRecording onvifRecording(onvifDevice);
	_trc__GetRecordingsResponse recordings;
	onvifRecording.GetRecordings(recordings);
	for (vector<tt__GetRecordingsResponseItem * >::iterator iter = 
			recordings.RecordingItem.begin(); 
			iter < recordings.RecordingItem.end(); ++iter)
	{

		tt__GetRecordingsResponseItem * pRecordings = *iter;
		printf("pRecordings %s\n", pRecordings->RecordingToken.c_str());
		tt__RecordingConfiguration *pRecordingConf = pRecordings->Configuration;
		if (pRecordingConf->Source)
		{
			printf("Recording SourceId %s\n", pRecordingConf->Source->SourceId.c_str());
			printf("Recording Name %s\n", pRecordingConf->Source->Name.c_str());
			printf("Recording Location %s\n", pRecordingConf->Source->Location.c_str());
			printf("Recording Description %s\n", pRecordingConf->Source->Description.c_str());
			printf("Recording Address %s\n", pRecordingConf->Source->Address.c_str());
		}

		string replayUrl;
		OnvifClientReplay onvifRelay(onvifDevice);
		onvifRelay.GetReplayUri(pRecordings->RecordingToken, replayUrl);
		printf("Relay Url %s\n", replayUrl.c_str());
	}
	
	// Onvif Receiver
	OnvifClientReceiver onvifReceiver(onvifDevice);
	_trv__GetReceiversResponse receivers;
	onvifReceiver.GetReceivers(receivers);
	for (vector<tt__Receiver * >::iterator iter = 
			receivers.Receivers.begin(); 
			iter < receivers.Receivers.end(); ++iter)
	{
		tt__Receiver * pReceivers = *iter;
		printf("pReceivers %s\n", pReceivers->Token.c_str());
	}

	OnvifClientEvent onvifEvent(onvifDevice);

	onvifEvent.Subscribe(eventNotify);
	
	OnvifClientEventNotify notify(soap_new());
	
    if ((ret = soap_bind(&notify, NULL, 9090, 100) == SOAP_INVALID_SOCKET ) ) 
	{
        printf("OnvifClientEventNotify::soap_bind Binding on %d port failed", 9090);
        return 0;
    }
	int timeStart = time(NULL);
	int currentTime = 0;

	//Loop to recevie the event
	while(1)
	{
		currentTime = time(NULL);
		if (currentTime - timeStart > 30)
		{
			onvifEvent.Renew();
		}
		//printf("soap_accept accepting\n");
		if( (ret = soap_accept(&notify)) == SOAP_INVALID_SOCKET) {
			//printf("soap_accept accepting timeout\n");
			continue;
		}

        if ( (soap_begin_serve(&notify)) != SOAP_OK) {
            printf("soap_begin_serve serve %d failed", ret);
            continue;
        }

        ret = notify.dispatch();
        continue;
	}*/
	
	return 0;
	
}




#include "stdafx.h"  

extern "C" {

#include "libavcodec/avcodec.h"
#include "libavdevice/avdevice.h"  
#include "libavformat/avformat.h"  
#include "libavfilter/avfilter.h"  
#include "libavutil/avutil.h"  
#include "libswscale/swscale.h"  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <math.h>  

 
}
/*
#include <iostream>

AVFormatContext *i_fmt_ctx;
AVStream *i_video_stream;
AVFormatContext *o_fmt_ctx;
AVStream *o_video_stream;

using namespace std;

int main(int argc, char **argv)
{
	avcodec_register_all();
	av_register_all();
	avformat_network_init();

	// should set to NULL so that avformat_open_input() allocate a new one 
	i_fmt_ctx = NULL;
	char rtspUrl[] = "rtsp://192.168.1.1:9099/stream";
	const char *filename = "realtime.mp4";
	if (avformat_open_input(&i_fmt_ctx, rtspUrl, NULL, NULL) != 0)
	{
		fprintf(stderr, "could not open input file\n");
		return -1;
	}

	if (avformat_find_stream_info(i_fmt_ctx, NULL)<0)
	{
		fprintf(stderr, "could not find stream info\n");
		return -1;
	}

	//av_dump_format(i_fmt_ctx, 0, argv[1], 0);  

	// find first video stream 
	for (unsigned i = 0; i<i_fmt_ctx->nb_streams; i++)
	{
		if (i_fmt_ctx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
		{
			i_video_stream = i_fmt_ctx->streams[i];
			break;
		}
	}
	if (i_video_stream == NULL)
	{
		fprintf(stderr, "didn't find any video stream\n");
		return -1;
	}

	avformat_alloc_output_context2(&o_fmt_ctx, NULL, NULL, filename);

	
	// since all input files are supposed to be identical (framerate, dimension, color format, ...)
	// we can safely set output codec values from first input file
	
	o_video_stream = avformat_new_stream(o_fmt_ctx, NULL);
	{
		AVCodecContext *c;
		c = o_video_stream->codec;
		c->bit_rate = 400000;
		c->codec_id = i_video_stream->codec->codec_id;
		c->codec_type = i_video_stream->codec->codec_type;
		c->time_base.num = i_video_stream->time_base.num;
		c->time_base.den = i_video_stream->time_base.den;
		fprintf(stderr, "time_base.num = %d time_base.den = %d\n", c->time_base.num, c->time_base.den);
		c->width = i_video_stream->codec->width;
		c->height = i_video_stream->codec->height;
		c->pix_fmt = i_video_stream->codec->pix_fmt;
		printf("%d %d %d", c->width, c->height, c->pix_fmt);
		c->flags = i_video_stream->codec->flags;
		c->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
		c->me_range = i_video_stream->codec->me_range;
		c->max_qdiff = i_video_stream->codec->max_qdiff;
		c->qmin = i_video_stream->codec->qmin;
		c->qmax = i_video_stream->codec->qmax;
		c->qcompress = i_video_stream->codec->qcompress;
	}

	avio_open(&o_fmt_ctx->pb, filename, AVIO_FLAG_WRITE);
	avformat_write_header(o_fmt_ctx, NULL);

	int last_pts = 0;
	int last_dts = 0;
	int64_t pts, dts;
	static int num = 1;

	system(" echo \"C:\\Program Files (x86)\\VideoLAN\\VLC\\vlc.exe\" rtsp://192.168.1.1:9099/stream");
	system("\"C:\\Program Files (x86)\\VideoLAN\\VLC\\vlc.exe\" rtsp://192.168.1.1:9099/stream");

	while (num<1000)
	{
		AVPacket i_pkt;
		av_init_packet(&i_pkt);
		i_pkt.size = 0;
		i_pkt.data = NULL;
		if (av_read_frame(i_fmt_ctx, &i_pkt) <0)
			break;
		
		// pts and dts should increase monotonically
		// pts should be >= dts
		
		i_pkt.flags |= AV_PKT_FLAG_KEY;
		pts = i_pkt.pts;
		i_pkt.pts += last_pts;
		dts = i_pkt.dts;
		i_pkt.dts += last_dts;
		i_pkt.stream_index = 0;

		//printf("%lld %lld\n", i_pkt.pts, i_pkt.dts);  
		
		printf("frame %d\n", num++);
		av_interleaved_write_frame(o_fmt_ctx, &i_pkt);
		//av_free_packet(&i_pkt);  
		//av_init_packet(&i_pkt);  

	}
	last_dts += dts;
	last_pts += pts;
	avformat_close_input(&i_fmt_ctx);
	av_write_trailer(o_fmt_ctx);
	avcodec_close(o_fmt_ctx->streams[0]->codec);
	av_freep(&o_fmt_ctx->streams[0]->codec);
	av_freep(&o_fmt_ctx->streams[0]);
	avio_close(o_fmt_ctx->pb);
	av_free(o_fmt_ctx);
	return 0;
}
*/
