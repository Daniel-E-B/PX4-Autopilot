class MavlinkStreamGimbalAngle : public MavlinkStream
{
public:
    const char *get_name() const
    {
        return MavlinkStreamGimbalAngle::get_name_static();
    }
    static const char *get_name_static()
    {
        return "MAVLINK_GIMBAL_ANGLE";
    }
    static uint16_t get_id_static()
    {
        return MAVLINK_MSG_ID_CA_TRAJECTORY;
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
        return MAVLINK_MSG_ID_CA_TRAJECTORY_LEN + MAVLINK_NUM_NON_PAYLOAD_BYTES;
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
            mavlink_ca_trajectory_t _msg_ca_trajectory;  //make sure mavlink_ca_trajectory_t is the definition of your custom MAVLink message

            _msg_ca_trajectory.timestamp = ;
            _msg_ca_trajectory.time_start_usec = ;
            _msg_ca_trajectory.time_stop_usec  = _;
            _msg_ca_trajectory.coefficients =_;
            _msg_ca_trajectory.seq_id = _;

            mavlink_msg_ca_trajectory_send_struct(_mavlink->get_channel(), &_msg_ca_trajectory);

            return true;
    }
};
