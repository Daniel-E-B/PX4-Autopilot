# enable access to xhost from the container
xhost +

# Run docker
nvidia-docker run -it --privileged \
    --env=LOCAL_USER_ID="$(id -u)" \
    -v /home/vtzoumas/Desktop/morphable-drones/PX4-Autopilot:/src/firmware:rw \
		# mount ubuntu's PX4-Autopilot dir to a dir called /src/firmware in the container
    -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
    -e DISPLAY=:1 \ # run echo $DISPLAY on device with screen
    -p 14556:14556/udp \ # important for QGC
    --name=px4gazebo px4io/px4-dev-simulation-focal:2021-12-11 bash
