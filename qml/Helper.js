.pragma library

function roundNumber(number, digits) {
	var multiple = Math.pow(10, digits);
	return Math.round(number * multiple) / multiple;
}

function formatTime(sec) {
	parseInt(sec)
	var value = sec
	var seconds = value % 60
	value /= 60
	value = (value > 1) ? Math.round(value) : 0
	var minutes = value % 60
	value /= 60
	value = (value > 1) ? Math.round(value) : 0
	var hours = value
	if (hours > 0) value = hours + "h:" + minutes + "m"
	else value = minutes + "m " + seconds + "s"
	return value
}

function formatDistance(meters) {
	parseInt(meters)
	var dist = Math.round(meters)
	if (dist > 1000) {
		dist = Math.round(dist / 1000)
		dist += " km"
	}
	else {
		dist += " m"
		return dist
	}
	return dist
}
