/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __PERF_SESSION2_H
#define __PERF_SESSION2_H

struct perf_session;
struct perf_tool;
struct perf_data;

struct perf_session *__perf_session__new(struct perf_data *data,
					 bool repipe, int repipe_fd,
					 struct perf_tool *tool);

static inline struct perf_session *perf_session__new(struct perf_data *data,
						     struct perf_tool *tool)
{
	return __perf_session__new(data, false, -1, tool);
}

struct perf_tool *perf_session__tool(struct perf_session *session);

void perf_session__delete(struct perf_session *session);

int perf_session__process_events(struct perf_session *session);

#endif /* __PERF_SESSION2_H */
