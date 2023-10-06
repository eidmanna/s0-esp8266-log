<script>
  import { onMount } from "svelte";
  import axios from "axios";
  import TopAppBar, { Row, Section, Title } from "@smui/top-app-bar";
  import IconButton from "@smui/icon-button";
  import CircularProgress from "@smui/circular-progress";
  import DataTable, { Head, Body, Row as RowT, Cell } from "@smui/data-table";
  import Card, { Content } from "@smui/card";

  let dataList;

  // set for development only !!!!!
  // let server = "http://192.168.0.89/data";

  let server = "/data";

  onMount(() => {
    loadData();
  });

  const loadData = () => {
    axios.get(server).then((response) => {
      console.log(response.data);
      dataList = response.data;
    });
  };
</script>

<main>
  <div class="top-app-bar-container">
    <TopAppBar variant="static" color="primary">
      <Row>
        <Section>
          <IconButton class="material-icons">menu</IconButton>
          <Title>Wärmepumpe</Title>
        </Section>
        <Section align="end" toolbar>
          <!-- <IconButton class="material-icons" aria-label="Download"
            >file_download</IconButton
          >
          <IconButton class="material-icons" aria-label="Print this page"
            >print</IconButton
          > -->
          <IconButton class="material-icons" aria-label="Bookmark this page"
            >bookmark</IconButton
          >
        </Section>
      </Row>
    </TopAppBar>
    <p />
    <div>
      <Card variant="outlined">
        <Content>
          <div>
            {#if dataList}
              <DataTable table$aria-label="ESP list" style="width: 100%;">
                <Head>
                  <RowT>
                    <Cell>Name</Cell>
                    <Cell>Wert</Cell>
                    <Cell>Einheit</Cell>
                  </RowT>
                </Head>
                <Body>
                  {#each dataList as data}
                    <RowT>
                      <Cell>{data.title}</Cell>
                      <Cell>{data.value}</Cell>
                      <Cell>{data.unit}</Cell>
                    </RowT>
                  {/each}
                </Body>
              </DataTable>
            {:else}
              <div style="display: flex; justify-content: center">
                <CircularProgress
                  style="height: 32px; width: 32px;"
                  indeterminate
                />
              </div>
            {/if}
          </div>
        </Content>
      </Card>
      <p />
      <Card variant="outlined">
        <Content>
          <iframe
            src="http://192.168.0.34:8082/echarts/index.html?preset=echarts.0.heatpump_power"
            title="Heatpump"
            name="heatpump"
            style="width: 100%; height: 400px; border: 0;"
          />
        </Content>
      </Card>
      <p />
      <Card variant="outlined">
        <Content>
          <iframe
            src="http://192.168.0.34:8082/echarts/index.html?preset=echarts.0.pv_power"
            title="PV"
            name="pv"
            style="width: 100%; height: 400px; border: 0;"
          />
        </Content>
      </Card>
    </div>
  </div>
</main>

<style>
</style>
