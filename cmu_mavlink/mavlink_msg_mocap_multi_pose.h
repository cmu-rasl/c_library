// MESSAGE MOCAP_MULTI_POSE PACKING

#define MAVLINK_MSG_ID_MOCAP_MULTI_POSE 216

typedef struct __mavlink_mocap_multi_pose_t
{
 int16_t pose[20]; /*< Robot pose (x, y, z, heading) in mm or mrad*/
 uint8_t npose; /*< Number of poses (max 5)*/
 uint8_t ids[5]; /*< Associated robot ids*/
} mavlink_mocap_multi_pose_t;

#define MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN 46
#define MAVLINK_MSG_ID_216_LEN 46

#define MAVLINK_MSG_ID_MOCAP_MULTI_POSE_CRC 69
#define MAVLINK_MSG_ID_216_CRC 69

#define MAVLINK_MSG_MOCAP_MULTI_POSE_FIELD_POSE_LEN 20
#define MAVLINK_MSG_MOCAP_MULTI_POSE_FIELD_IDS_LEN 5

#define MAVLINK_MESSAGE_INFO_MOCAP_MULTI_POSE { \
	"MOCAP_MULTI_POSE", \
	3, \
	{  { "pose", NULL, MAVLINK_TYPE_INT16_T, 20, 0, offsetof(mavlink_mocap_multi_pose_t, pose) }, \
         { "npose", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_mocap_multi_pose_t, npose) }, \
         { "ids", NULL, MAVLINK_TYPE_UINT8_T, 5, 41, offsetof(mavlink_mocap_multi_pose_t, ids) }, \
         } \
}


/**
 * @brief Pack a mocap_multi_pose message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param npose Number of poses (max 5)
 * @param ids Associated robot ids
 * @param pose Robot pose (x, y, z, heading) in mm or mrad
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mocap_multi_pose_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t npose, const uint8_t *ids, const int16_t *pose)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN];
	_mav_put_uint8_t(buf, 40, npose);
	_mav_put_int16_t_array(buf, 0, pose, 20);
	_mav_put_uint8_t_array(buf, 41, ids, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN);
#else
	mavlink_mocap_multi_pose_t packet;
	packet.npose = npose;
	mav_array_memcpy(packet.pose, pose, sizeof(int16_t)*20);
	mav_array_memcpy(packet.ids, ids, sizeof(uint8_t)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOCAP_MULTI_POSE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN);
#endif
}

/**
 * @brief Pack a mocap_multi_pose message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param npose Number of poses (max 5)
 * @param ids Associated robot ids
 * @param pose Robot pose (x, y, z, heading) in mm or mrad
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mocap_multi_pose_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t npose,const uint8_t *ids,const int16_t *pose)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN];
	_mav_put_uint8_t(buf, 40, npose);
	_mav_put_int16_t_array(buf, 0, pose, 20);
	_mav_put_uint8_t_array(buf, 41, ids, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN);
#else
	mavlink_mocap_multi_pose_t packet;
	packet.npose = npose;
	mav_array_memcpy(packet.pose, pose, sizeof(int16_t)*20);
	mav_array_memcpy(packet.ids, ids, sizeof(uint8_t)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOCAP_MULTI_POSE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN);
#endif
}

/**
 * @brief Encode a mocap_multi_pose struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mocap_multi_pose C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mocap_multi_pose_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mocap_multi_pose_t* mocap_multi_pose)
{
	return mavlink_msg_mocap_multi_pose_pack(system_id, component_id, msg, mocap_multi_pose->npose, mocap_multi_pose->ids, mocap_multi_pose->pose);
}

/**
 * @brief Encode a mocap_multi_pose struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mocap_multi_pose C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mocap_multi_pose_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mocap_multi_pose_t* mocap_multi_pose)
{
	return mavlink_msg_mocap_multi_pose_pack_chan(system_id, component_id, chan, msg, mocap_multi_pose->npose, mocap_multi_pose->ids, mocap_multi_pose->pose);
}

/**
 * @brief Send a mocap_multi_pose message
 * @param chan MAVLink channel to send the message
 *
 * @param npose Number of poses (max 5)
 * @param ids Associated robot ids
 * @param pose Robot pose (x, y, z, heading) in mm or mrad
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mocap_multi_pose_send(mavlink_channel_t chan, uint8_t npose, const uint8_t *ids, const int16_t *pose)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN];
	_mav_put_uint8_t(buf, 40, npose);
	_mav_put_int16_t_array(buf, 0, pose, 20);
	_mav_put_uint8_t_array(buf, 41, ids, 5);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_MULTI_POSE, buf, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_MULTI_POSE, buf, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN);
#endif
#else
	mavlink_mocap_multi_pose_t packet;
	packet.npose = npose;
	mav_array_memcpy(packet.pose, pose, sizeof(int16_t)*20);
	mav_array_memcpy(packet.ids, ids, sizeof(uint8_t)*5);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_MULTI_POSE, (const char *)&packet, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_MULTI_POSE, (const char *)&packet, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mocap_multi_pose_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t npose, const uint8_t *ids, const int16_t *pose)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 40, npose);
	_mav_put_int16_t_array(buf, 0, pose, 20);
	_mav_put_uint8_t_array(buf, 41, ids, 5);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_MULTI_POSE, buf, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_MULTI_POSE, buf, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN);
#endif
#else
	mavlink_mocap_multi_pose_t *packet = (mavlink_mocap_multi_pose_t *)msgbuf;
	packet->npose = npose;
	mav_array_memcpy(packet->pose, pose, sizeof(int16_t)*20);
	mav_array_memcpy(packet->ids, ids, sizeof(uint8_t)*5);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_MULTI_POSE, (const char *)packet, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_MULTI_POSE, (const char *)packet, MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE MOCAP_MULTI_POSE UNPACKING


/**
 * @brief Get field npose from mocap_multi_pose message
 *
 * @return Number of poses (max 5)
 */
static inline uint8_t mavlink_msg_mocap_multi_pose_get_npose(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Get field ids from mocap_multi_pose message
 *
 * @return Associated robot ids
 */
static inline uint16_t mavlink_msg_mocap_multi_pose_get_ids(const mavlink_message_t* msg, uint8_t *ids)
{
	return _MAV_RETURN_uint8_t_array(msg, ids, 5,  41);
}

/**
 * @brief Get field pose from mocap_multi_pose message
 *
 * @return Robot pose (x, y, z, heading) in mm or mrad
 */
static inline uint16_t mavlink_msg_mocap_multi_pose_get_pose(const mavlink_message_t* msg, int16_t *pose)
{
	return _MAV_RETURN_int16_t_array(msg, pose, 20,  0);
}

/**
 * @brief Decode a mocap_multi_pose message into a struct
 *
 * @param msg The message to decode
 * @param mocap_multi_pose C-struct to decode the message contents into
 */
static inline void mavlink_msg_mocap_multi_pose_decode(const mavlink_message_t* msg, mavlink_mocap_multi_pose_t* mocap_multi_pose)
{
#if MAVLINK_NEED_BYTE_SWAP
	mavlink_msg_mocap_multi_pose_get_pose(msg, mocap_multi_pose->pose);
	mocap_multi_pose->npose = mavlink_msg_mocap_multi_pose_get_npose(msg);
	mavlink_msg_mocap_multi_pose_get_ids(msg, mocap_multi_pose->ids);
#else
	memcpy(mocap_multi_pose, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_MOCAP_MULTI_POSE_LEN);
#endif
}
