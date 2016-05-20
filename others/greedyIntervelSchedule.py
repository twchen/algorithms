''' Input: a list of activities (s, f) with start time s and finish time f.
    Output: a list of maximum size consisting of mutually compatible activities.
    Time Complexity: O(n*log(n))
'''

def greedyIntervalSchedule(activities):
	activities.sort(key=lambda x: x[1]) # sort the activities in increasing order of finish time
	scheduled_activities = []
	current_finish_time = 0
	for i in range(0, len(activities)):
		if activities[i][0] >= current_finish_time: # start time >= finish time of the last scheduled activity
			scheduled_activities.append(activities[i])
			current_finish_time = activities[i][1]
	return scheduled_activities

# test
A = [(1, 4), (3, 5), (0, 6), (5, 7), (3, 9), (5, 9), (6, 10), (8, 11), (8, 12), (2, 14), (12, 16)]
print greedyIntervalSchedule(A)
assert len(greedyIntervalSchedule(A)) == 4
