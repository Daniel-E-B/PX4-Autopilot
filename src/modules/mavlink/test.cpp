class MavlinkStreamGimbalAngle : public MavlinkStream
{
public:
    const char *get_name() const
    {
        return MavlinkStreamGimbalAngle::get_name_static();
    }
    static const char *get_name_static()
    {
        return "MAVLINK_GIMBAL_ANGLE_CMD";
    }
    static uint16_t get_id_static()
    {
        return MAVLINK_MSG_ID_GIMBAL_ANGLE_CMD;
    }
    uint16_t get_id()
    {
        return get_id_static();
    }
    static MavlinkStream *new_instance(Mavlink *mavlink)
    {
        return new MavlinkStreamGimbalAngle(mavlink);
    }
    unsigned get_size()
    {
        return MAVLINK_MSG_ID_GIMBAL_ANGLE_CMD_LEN + MAVLINK_NUM_NON_PAYLOAD_BYTES;
    }

private:
    /* do not allow top copying this class */
    MavlinkStreamGimbalAngle(MavlinkStreamGimbalAngle &);
    MavlinkStreamGimbalAngle& operator = (const MavlinkStreamGimbalAngle &);

protected:
    explicit MavlinkStreamGimbalAngle(Mavlink *mavlink) : MavlinkStream(mavlink)
    {}

    bool send() override
    {
            mavlink_gimbal_angle_cmd_t _msg_gimbal_angle_cmd_t;

            _msg_gimbal_angle_cmd_t.a1 = 25.0;
            _msg_gimbal_angle_cmd_t.a2 = 35.0;
            _msg_gimbal_angle_cmd_t.a3 = 45.0;
            _msg_gimbal_angle_cmd_t.a4 = 55.0;
            _msg_gimbal_angle_cmd_t.a5 = 65.0;

            mavlink_msg_gimbal_angle_cmd_send_struct(_mavlink->get_channel(), &_msg_gimbal_angle_cmd_t);

            return true;
    }
};
